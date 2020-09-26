/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 11:51:43 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

double	ray_casting(t_sets *s, double curr_angle, int wall_x)
{
	t_dist	dist;

	dist = get_dist_and_texture(s, curr_angle);
	s->curr_txtr.x = (int)(SCALE * dist.x);
	draw_column(s, wall_x, dist.dist);
	return (dist.dist);
}

void	draw_img(t_sets *s, int is_save)
{
	t_view	view;
	int		wall_x;
	double	distances[s->wdw.r_x];

	if (!(get_new_image(s)))
		return ;
	wall_x = 0;
	view.start = s->plr_d + FOV_HALF;
	view.end = s->plr_d - FOV_HALF;
	while (view.start > view.end)
	{
		// double	step_xy[2];
		// double	curr_xy[2];
		// step_xy[0] = cos(view.start);
		// step_xy[1] = -sin(view.end);
		// curr_xy[0] = s->plr_x;
		// curr_xy[1] = s->plr_y;
		// while (s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] &&\
		// s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '1' && \
		// s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '2')
		// {
		// 	mlx_pixel_put(s->wdw.mlx, s->wdw.wdw, curr_xy[0], curr_xy[1], 0xC2171D);
		// 	curr_xy[0] += step_xy[0];
		// 	curr_xy[1] += step_xy[1];
		// }

		distances[wall_x] = ray_casting(s, ft_correct_angle(view.start), wall_x);
		wall_x++;
		view.start -= (FOV / s->wdw.r_x);
	}
	draw_sprites(s, distances);
	draw_2dmap(s);
	mlx_put_image_to_window(s->wdw.mlx, s->wdw.wdw, s->wdw.img_data.img, 0, 0);
	(void)is_save;
	// if (!is_save)
	// 	mlx_do_sync(s->wdw.mlx);
}

void	create_window(t_sets sets, int is_save)
{
	if (!sets.wdw.mlx)
		return mlx_err();
	if (!(sets.wdw.wdw = mlx_new_window(sets.wdw.mlx, \
		sets.wdw.r_x, sets.wdw.r_y, "cub3d")))
		return mlx_err();
	// draw_img(&sets);
	if (!is_save)
	{
		draw_img(&sets, 0);
		mlx_hook(sets.wdw.wdw, 2, 1L<<0, button_pressed, &sets);
		mlx_hook(sets.wdw.wdw, 17, 1L<<0, close_mlx, &sets);
		mlx_loop(sets.wdw.mlx);
	}
	else
	{
		draw_img(&sets, 1);
		save_bmp(&sets, 0);
	}
	close_mlx(&sets);
}
