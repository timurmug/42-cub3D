/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/21 18:36:49 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pixel_put(t_sets *s, int x, int y, int color)
{
    char    *dst;

    dst = s->wdw.img_data.addr + (y * s->wdw.img_data.size_line + \
		x * (s->wdw.img_data.bpp / 8));
    *(unsigned int*)dst = color;
}

void	put_pixel_img(t_img img, t_img texture,
		int index, int index_texture)
{
	img.addr[index] = texture.addr[index_texture];
	img.addr[index + 1] = texture.addr[index_texture + 1];
	img.addr[index + 2] = texture.addr[index_texture + 2];
	img.addr[index + 3] = texture.addr[index_texture + 3];
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

	// int	index;
	// int	index_texture;
	// t_txtr txtr = s->w_txtr;
	// txtr.step = 1.0 * txtr.img_data.height / height;
	// // ft_putnbr_fd(txtr.step, 1);
	// // printf("%lf\n", txtr.step);
	// txtr.x *= (txtr.img_data.bpp / 8);
	// wall_x *= s->wdw.img_data.bpp / 8;
	// // printf("%d\n", wall_x);
	//
	// double txtr_position = (wall_y - s->wdw.r_y / 2 + height / 2) * txtr.step;
	// printf("%lf\n", txtr_position);


	while (height-- > 0)
	{
		// txtr.y = (int)txtr_position & (txtr.img_data.height - 1);
		// index_texture = txtr.y * txtr.img_data.size_line + txtr.x;
		// index = wall_y * s->wdw.img_data.size_line + wall_x;
		// if (index > 0 && index < s->wdw.img_data.size_line * s->wdw.r_y)
		// 	put_pixel_img(s->wdw.img_data, txtr.img_data, index, index_texture);
		// txtr_position += txtr.step;
		// wall_y++;

		if (wall_y < s->wdw.r_y)
		{
			pixel_put(s, wall_x, wall_y, 0x999999);
			wall_y++;
		}
	}
	draw_ceiling_floor(s, wall_x, wall_y, 0);

	// (void)txtr_position;
}

void	draw_column2(t_sets *s, int wall_x, double degree, double	ray)
{
	// double	ray;
	double	height;
	double	wall_y;

	(void)degree;
	// ray = sqrt(pow(s->plr_x - curr_xy[0], 2) + pow(s->plr_y - curr_xy[1], 2));
	// ray *= cos(s->plr_d - degree);
	height = CELL / ray * ((double)s->plr_x / 2 / tanf(FOV_HALF));
	wall_y = (s->wdw.r_y / 2 - height / 2);
	draw_ceiling_floor(s, wall_x, wall_y, 1);
	if (height >= s->wdw.r_y)
		height = s->wdw.r_y;
	if (wall_y < 0)
		wall_y = 0;
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

int		get_new_image(t_sets *s)
{
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

#include <stdio.h>
void	calc_map(t_sets *s)
{
	// double	step_xy[2];
	// double	curr_xy[2];
	double	start_end[2];
	int		wall_x;

	if (!(get_new_image(s)))
		return ;
	wall_x = 0;
	start_end[0] = s->plr_d + FOV_HALF;
	start_end[1] = s->plr_d - FOV_HALF;
	while (start_end[0] > start_end[1])
	{
		// step_xy[0] = cos(start_end[0]);
		// step_xy[1] = -sin(start_end[0]);
		// curr_xy[0] = s->plr_x;
		// curr_xy[1] = s->plr_y;
		// while (s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] &&\
		// s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '1' && \
		// s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '2')
		// {
		// 	// mlx_pixel_put(s->wdw.mlx, s->wdw.wdw, curr_xy[0], curr_xy[1], 0xC2171D);
		// 	curr_xy[0] += step_xy[0];
		// 	curr_xy[1] += step_xy[1];
		// }


		int ray1 = distance_to_wall_h(s, start_end[0]);
		// int ray2 = distance_to_wall_v(s, start_end[0]);
		// printf("%d ", ray1);
		// printf("%d\n", ray2);
		// (void)ray1;
		// (void)ray2;
		// (void)step_xy;
		// (void)curr_xy;
		// if (ray1 > ray2)
			draw_column2(s, wall_x, start_end[0], ray1);
		// else
			// draw_column2(s, wall_x, start_end[0], ray2);



		// draw_column(s, curr_xy, wall_x, start_end[0]);
		wall_x++;
		// wall_x *= (s->wdw.img_data.bpp / 8);
		start_end[0] -= FOV / s->wdw.r_x;
	}
	mlx_put_image_to_window(s->wdw.mlx, s->wdw.wdw, s->wdw.img_data.img, 0, 0);
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
