/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/23 11:16:14 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling_floor2(t_sets *s, int x, double wall_y, int isceil)
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

void	draw_column2(t_sets *s, double curr_xy[2], int wall_x, double degree)
{
	double	ray;
	double	height;
	double	wall_y;

	ray = sqrt(pow(s->plr_x - curr_xy[0], 2) + pow(s->plr_y - curr_xy[1], 2));
	ray *= cos(s->plr_d - degree);

	height = CELL / ray * ((double)s->wdw.r_x / 2 / tanf(FOV_HALF));
	wall_y = (s->wdw.r_y / 2 - height / 2);
	draw_ceiling_floor2(s, wall_x, wall_y, 1);
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
			pixel_put(s, curr_xy[0], wall_y, 0x999999);
			curr_xy[0]++;
			wall_y++;
		}
	}
	draw_ceiling_floor2(s, wall_x, wall_y, 0);

	// (void)txtr_position;
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


t_dist	dist_to_wall_init(t_dist dist_to_wall, double pov, double angle)
{
	t_dist	dist;

	dist.x = modf(dist_to_wall.x / CELL, &dist_to_wall.x);
	dist.dist = dist_to_wall.dist * cosf(pov - angle);
	return (dist);
}

void	calc_map(t_sets *s)
{
	// double	step_xy[2];
	// double	curr_xy[2];
	// double	start_end[2];
	t_view	view;
	int		wall_x;
	double	curr_angle;

	if (!(get_new_image(s)))
		return ;
	wall_x = 0;
	// start_end[0] = s->plr_d + FOV_HALF;
	// start_end[1] = s->plr_d - FOV_HALF;

	view.start = s->plr_d + FOV_HALF;
	view.end = s->plr_d - FOV_HALF;
	// while (start_end[0] > start_end[1])
	while (view.start > view.end)
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
		// draw_column2(s, curr_xy, wall_x, start_end[0]);

		curr_angle = ft_correct_angle(view.start);
		t_dist dist1 = distance_to_wall_h(s, curr_angle);
		t_dist dist2 = distance_to_wall_v(s, curr_angle);
		get_wall_texture(s, curr_angle, dist1.dist, dist2.dist);
		t_dist dist;
		if (dist1.dist < dist2.dist)
			dist = dist_to_wall_init(dist1, s->plr_d, curr_angle);
		else
			dist = dist_to_wall_init(dist2, s->plr_d, curr_angle);
		s->curr_txtr.x = (int)(SCALE * dist.x);

		if (dist1.dist < dist2.dist)
		{
			// draw_column(s, wall_x, start_end[0], ray1, 0x004DFF);
			if (curr_angle < M_PI)
				draw_column(s, wall_x, view.start, dist1.dist, 0x004DFF);
			else
				draw_column(s, wall_x, view.start, dist1.dist, 0x55c87e);
		}
		else
		{
			if (curr_angle > M_PI / 2 && curr_angle < M_PI * 3 / 2)
				draw_column(s, wall_x, view.start, dist2.dist, 0x999999);
			else
				draw_column(s, wall_x, view.start, dist2.dist, 0xc88855);
		}

		wall_x++;
		// wall_x *= (s->wdw.img_data.bpp / 8);
		view.start -= (FOV / s->wdw.r_x);
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
