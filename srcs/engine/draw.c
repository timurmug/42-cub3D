/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/17 15:20:38 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	pixel_put(t_sets *s, int x, int y, int color)
// {
// 	char	*dst;
//
// 	dst = s->wdw.addr + (x * (s->wdw.bpp) +  y * s->wdw.size_line);
// 	*(int *)dst = color;
// }

void	my_mlx_pixel_put(t_sets *s, int x, int y, int color)
{
    char    *dst;

    dst = s->wdw.addr + (y * s->wdw.size_line + x * (s->wdw.bpp / 8));
    *(unsigned int*)dst = color;
}

void	draw_column(t_sets *s, double curr_xy[2], int x)
{
	double	ray;
	double	height;
	double	temp;

	ray = sqrt(pow(s->plr_x - curr_xy[0], 2) + pow(s->plr_y - curr_xy[1], 2));
	height = CELL / ray * ((double)s->plr_x / 2 / tanf(FOV_HALF));
	temp = (s->wdw.r_y / 2 - height / 2);
	while (height > 0)
	{
		// mlx_pixel_put(s->wdw.mlx, s->wdw .wdw, x, temp, 0x999999);
		// pixel_put(s, x, temp, 0x999999);
		my_mlx_pixel_put(s, x, temp, 0x999999);
		temp++;
		height--;
	}
	mlx_put_image_to_window(s->wdw.mlx, s->wdw.wdw, s->wdw.img, 0, 0);
}

void	calc_map(t_sets *s)
{
	double	step_xy[2];
	double	curr_xy[2];
	double	start_end[2];
	int		x = s->wdw.r_x;

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
		draw_column(s, curr_xy, x);
		x--;
		start_end[0] += FOV / s->wdw.r_x;
	}
}

void	create_window(t_sets sets)
{
	sets.wdw.wdw = mlx_new_window(sets.wdw.mlx, \
		sets.wdw.r_x, sets.wdw.r_y, "cub3d");
	if (!(sets.wdw.img = mlx_new_image(sets.wdw.mlx, \
		sets.wdw.r_x, sets.wdw.r_y)))
	{
		ft_putendl_fd(SMTH_ERR, 1);
		return ;
	}
	// mlx_put_image_to_window(sets.wdw.mlx, \
	// 	sets.wdw.wdw, sets.wdw.img, 0, 0);
	sets.wdw.addr = mlx_get_data_addr(sets.wdw.img, \
		&sets.wdw.bpp, &sets.wdw.size_line, &sets.wdw.endian);
	calc_map(&sets);
	// mlx_key_hook(sets.wdw, key_press, &sets);
	mlx_hook(sets.wdw.wdw, 2, 1L<<0, button_pressed, &sets);
	mlx_hook(sets.wdw.wdw, 17, 1L<<0, cross_pressed, &sets);

	mlx_loop(sets.wdw.mlx);
}
