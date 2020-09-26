/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:30:13 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 14:24:08 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	change_dir(t_sets *sets, int isleft)
{
	if (isleft)
		sets->plr_d += M_PI / 180 * 5;
	else
		sets->plr_d -= M_PI / 180 * 5;
	if (sets->plr_d < 0)
		sets->plr_d += 2 * M_PI;
	else if (sets->plr_d >= 2 * M_PI)
		sets->plr_d -= 2 * M_PI;
}

void	check_wall(t_sets *sets, t_coords_int dec)
{
	t_coords_int map;

	map.x = (sets->plr_x + dec.x) / SCALE;
	map.y = (sets->plr_y + dec.y) / SCALE;
	if (sets->map[map.y][map.x] && \
		sets->map[map.y][map.x] != '1' && sets->map[map.y][map.x] != '2')
	{
		sets->plr_y += dec.y;
		sets->plr_x += dec.x;
	}
}

void	change_x(t_sets *sets, int isright)
{
	t_coords_int dec;

	if (isright)
	{
		dec.y = -sin(sets->plr_d - M_PI / 2) * MOV_SPEED;
		dec.x = cos(sets->plr_d - M_PI / 2) * MOV_SPEED;
	}
	else
	{
		dec.y = sin(sets->plr_d - M_PI / 2) * MOV_SPEED;
		dec.x = -cos(sets->plr_d - M_PI / 2) * MOV_SPEED;
	}
	check_wall(sets, dec);
}

void	change_y(t_sets *sets, int isdown)
{
	t_coords_int dec;

	if (isdown)
	{
		dec.y = sin(sets->plr_d) * (MOV_SPEED + 2);
		dec.x = -cos(sets->plr_d) * (MOV_SPEED + 2);
	}
	else
	{
		dec.y = -sin(sets->plr_d) * (MOV_SPEED + 2);
		dec.x = cos(sets->plr_d) * (MOV_SPEED + 2);
	}
	check_wall(sets, dec);
}

int		button_pressed(int key, t_sets *sets)
{
	mlx_clear_window(sets->wdw.mlx, sets->wdw.wdw);
	if (key == ESC_BUTTON)
		return (close_mlx(sets));
	else if (key == LEFT_BUTTON)
		change_dir(sets, 1);
	else if (key == RIGHT_BUTTON)
		change_dir(sets, 0);
	else if (key == W_BUTTON)
		change_y(sets, 0);
	else if (key == S_BUTTON)
		change_y(sets, 1);
	else if (key == A_BUTTON)
		change_x(sets, 0);
	else if (key == D_BUTTON)
		change_x(sets, 1);
	draw_img(sets, 0);
	return (0);
}
