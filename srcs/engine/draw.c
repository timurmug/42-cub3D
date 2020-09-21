/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/21 11:25:38 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pixel_put(t_sets *s, int x, int y, int color)
{
    char    *dst;

	// dst = s->wdw.addr + (y * s->wdw.size_line + x * (s->wdw.bpp / 8));
    dst = s->wdw.img_data.addr + (y * s->wdw.img_data.size_line + x * (s->wdw.img_data.bpp / 8));
    *(unsigned int*)dst = color;
}

void	draw_ceiling_floor(t_sets *s, int x, double wall_y, int isceil)
{
	double temp_y;

	if (isceil)
	{
		temp_y = 0;
		if (wall_y > 0)
			while (temp_y < wall_y)
				pixel_put(s, x, temp_y++, s->ceiling_col);
	}
	else if (wall_y <= s->wdw.r_y)
		while (wall_y <= s->wdw.r_y)
			pixel_put(s, x, wall_y++, s->floor_col);
}

void	draw_column(t_sets *s, double curr_xy[2], int wall_x, double degree)
{
	double	ray;
	double	height;
	double	wall_y;

	ray = sqrt(pow(s->plr_x - curr_xy[0], 2) + pow(s->plr_y - curr_xy[1], 2));
	ray *= cos(s->plr_d - degree);
	height = CELL / ray * ((double)s->plr_x / 2 / tanf(FOV_HALF));
	wall_y = (s->wdw.r_y / 2 - height / 2);
	draw_ceiling_floor(s, wall_x, wall_y, 1);
	if (height >= s->wdw.r_y)
		height = s->wdw.r_y;
	if (wall_y < 0)
		wall_y = 0;
	// s->
	while (height > 0)
	{
		if (wall_y < s->wdw.r_y)
		{
			pixel_put(s, wall_x, wall_y, 0x999999);
			wall_y++;
		}
		height--;
	}
	draw_ceiling_floor(s, wall_x, wall_y, 0);
}

// void	draw_column(t_sets *s, int wall_x, double degree, double	ray)
// {
// 	// double	ray;
// 	double	height;
// 	double	wall_y;
//
// 	// ray = sqrt(pow(s->plr_x - curr_xy[0], 2) + pow(s->plr_y - curr_xy[1], 2));
// 	ray *= cos(s->plr_d - degree);
// 	height = CELL / ray * ((double)s->plr_x / 2 / tanf(FOV_HALF));
// 	wall_y = (s->wdw.r_y / 2 - height / 2);
// 	draw_ceiling_floor(s, wall_x, wall_y, 1);
// 	if (height >= s->wdw.r_y)
// 		height = s->wdw.r_y;
// 	if (wall_y < 0)
// 		wall_y = 0;
// 	while (height > 0)
// 	{
// 		if (wall_y < s->wdw.r_y)
// 		{
// 			pixel_put(s, wall_x, wall_y, 0x999999);
// 			wall_y++;
// 		}
// 		height--;
// 	}
// 	draw_ceiling_floor(s, wall_x, wall_y, 0);
// }

int		get_new_image(t_sets *s)
{
	// if (s->wdw.img)
	// 	mlx_destroy_image(s->wdw.mlx, s->wdw.img);
	//  s->wdw.img = NULL;
	// if (!(s->wdw.img = mlx_new_image(s->wdw.mlx, \
	// 	s->wdw.r_x, s->wdw.r_y + 1)))
	// {
	// 	ft_putendl_fd(SMTH_ERR, 1);
	// 	return (0);
	// }
	// s->wdw.addr = mlx_get_data_addr(s->wdw.img, \
	// 	&s->wdw.bpp, &s->wdw.size_line, &s->wdw.endian);
	// return (1);

	if (s->wdw.img_data.img)
		mlx_destroy_image(s->wdw.mlx, s->wdw.img_data.img);
	s->wdw.img_data.img = NULL;
	if (!(s->wdw.img_data.img = mlx_new_image(s->wdw.mlx, \
		s->wdw.r_x, s->wdw.r_y + 1)))
	{
		ft_putendl_fd(SMTH_ERR, 1);
		return (0);
	}
	s->wdw.img_data.addr = mlx_get_data_addr(s->wdw.img_data.img, \
		&s->wdw.img_data.bpp, &s->wdw.img_data.size_line, &s->wdw.img_data.endian);
	return (1);
}

void	calc_map(t_sets *s)
{
	double	step_xy[2];
	double	curr_xy[2];
	double	start_end[2];
	int		wall_x;

	if (!(get_new_image(s)))
		return ;
	wall_x = 0;
	start_end[0] = s->plr_d + FOV_HALF;
	start_end[1] = s->plr_d - FOV_HALF;
	while (start_end[0] > start_end[1])
	{
		step_xy[0] = cos(start_end[0]);
		step_xy[1] = -sin(start_end[0]);
		curr_xy[0] = s->plr_x;
		curr_xy[1] = s->plr_y;
		while (s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] &&\
		s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '1' && \
		s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '2')
		{
			// mlx_pixel_put(s->wdw.mlx, s->wdw.wdw, curr_xy[0], curr_xy[1], 0xC2171D);
			curr_xy[0] += step_xy[0];
			curr_xy[1] += step_xy[1];
		}

		// //1 2
		// int ya;
		// if (start_end[0] > 0 && start_end[0] < M_PI)
		// {
		// 	step_xy[1] = (int)s->plr_y / SCALE * SCALE - 1;
		// 	ya = - SCALE;
		// }
		// else
		// {
		// 	step_xy[1] = (int)s->plr_y / SCALE * SCALE + SCALE;
		// 	ya = SCALE;
		// }
		// step_xy[0] = s->plr_x + (s->plr_y - step_xy[1]) / tan(start_end[0]);
		// //3
		// int xa = SCALE / tan(start_end[0]);
		// //4
		// curr_xy[1] = step_xy[1] / SCALE;
		// curr_xy[0] = step_xy[0] / SCALE;
		// while (s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] &&\
		// s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '1' && \
		// s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '2')
		// {
		// 	// mlx_pixel_put(s->wdw.mlx, s->wdw.wdw, curr_xy[0], curr_xy[1], 0xC2171D);
		// 	// curr_xy[0] += step_xy[0];
		// 	// curr_xy[1] += step_xy[1];
		//
		// 	curr_xy[0] += xa;
		// 	curr_xy[1] += ya;
		// }
		//
		// // int dist_x1 = s->plr_x - curr_xy[0];
		// // int dist_y1 = s->plr_y - curr_xy[1];
		// int dist_x1 = curr_xy[0];
		// int dist_y1 = curr_xy[1];
		//
		// //1 2
		// if ((start_end[0] <= 0 && start_end[0] > 3 * M_PI / 2) ||
		// 	(start_end[0] > 0 && start_end[0] > M_PI / 2))
		// {
		// 	step_xy[0] = (int)s->plr_x  / SCALE * SCALE + SCALE;
		// 	xa = SCALE;
		// }
		// else
		// {
		// 	step_xy[0] = (int)s->plr_x / SCALE * SCALE - 1;
		// 	xa = -SCALE;
		// }
		// //3
		// ya = SCALE / tan(start_end[0]);
		// //4
		// curr_xy[1] = step_xy[1] / SCALE;
		// curr_xy[0] = step_xy[0] / SCALE;
		// while (s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] &&\
		// s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '1' && \
		// s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '2')
		// {
		// 	curr_xy[0] += xa;
		// 	curr_xy[1] += ya;
		// }
		// // int dist_x2 = s->plr_x - curr_xy[0];
		// // int dist_y2 = s->plr_y - curr_xy[1];
		// int dist_x2 = curr_xy[0];
		// int dist_y2 = curr_xy[1];
		//
		// int ray1 = sqrt(pow(s->plr_x - dist_x1, 2) + pow(s->plr_y - dist_y1, 2));
		// int ray2 = sqrt(pow(s->plr_x - dist_x2, 2) + pow(s->plr_y - dist_y2, 2));
		// if (ray1 < ray2)
		// 	draw_column(s, wall_x, start_end[0], ray1);
		// else
		// 	draw_column(s, wall_x, start_end[0], ray2);



		draw_column(s, curr_xy, wall_x, start_end[0]);
		wall_x++;
		start_end[0] -= FOV / s->wdw.r_x;
	}
	mlx_put_image_to_window(s->wdw.mlx, s->wdw.wdw, s->wdw.img_data.img, 0, 0);
	// mlx_put_image_to_window(s->wdw.mlx, s->wdw.wdw, s->wdw.img, 0, 0);

}

void	create_window(t_sets sets)
{
	if (!sets.wdw.mlx)
		return mlx_err();
	if (!(sets.wdw.wdw = mlx_new_window(sets.wdw.mlx, \
		sets.wdw.r_x, sets.wdw.r_y, "cub3d")))
		return mlx_err();
	calc_map(&sets);
	mlx_hook(sets.wdw.wdw, 2, 1L<<0, button_pressed, &sets);
	mlx_hook(sets.wdw.wdw, 17, 1L<<0, cross_pressed, &sets);
	mlx_loop(sets.wdw.mlx);
}
