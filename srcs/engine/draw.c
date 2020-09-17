/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/17 12:31:35 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_column(t_sets *s, double curr_xy[2], int x)
{
	double	ray;
	double	height;
	double	temp;

	ray = sqrt(pow(s->plr_x - curr_xy[0], 2) + pow(s->plr_y - curr_xy[1], 2));
	height = CELL / ray * ((double)s->plr_x / 2 / tanf(FOV_HALF));
	temp = (s->r_y / 2 - height / 2);
	while (height > 0)
	{
		mlx_pixel_put(s->mlx, s->wdw, x, temp, 0xC2171D);
		temp++;
		height--;
	}
}

void	calc_map(t_sets *s)
{
	double	step_xy[2];
	double	curr_xy[2];
	double	start_end[2];
	int		x = 0;

	// draw_2dmap(s);
	start_end[0] = s->plr_d - FOV_HALF;
	start_end[1] = s->plr_d + FOV_HALF;
	while (start_end[0] < start_end[1])
	{
		step_xy[0] = cos(start_end[0]);
		step_xy[1] = -sin(start_end[0]);
		curr_xy[0] = s->plr_x;
		curr_xy[1] = s->plr_y;
		while (s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] &&\
		s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '1' && \
		s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '2')
		{
			// mlx_pixel_put(s->mlx, s->wdw, curr_xy[0], curr_xy[1], 0xC2171D);
			curr_xy[0] += step_xy[0];
			curr_xy[1] += step_xy[1];
		}
		draw_column(s, curr_xy, s->r_x - x);
		x++;
		start_end[0] += FOV / s->r_x;
	}
}

void	create_window(t_sets sets)
{
	sets.wdw = mlx_new_window(sets.mlx, sets.r_x, sets.r_y, "cub3d");
	calc_map(&sets);
	// mlx_key_hook(sets.wdw, key_press, &sets);
	mlx_hook(sets.wdw, 2, 1L<<0, key_press, &sets);
	mlx_hook(sets.wdw, 17, 1L<<0, key_exit, &sets);

	mlx_loop(sets.mlx);
}
