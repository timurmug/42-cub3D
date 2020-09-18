/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:30:13 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/18 12:34:44 by qtamaril         ###   ########.fr       */
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

void	change_x(t_sets *sets, int isright)
{
	int map_x;
	int map_y;
	int dec;

	if (isright)
		dec = 6;
	else
		dec = -6;
	map_x = (sets->plr_x + dec) / SCALE;
	map_y = sets->plr_y / SCALE;
	if (sets->map[map_y][map_x] && sets->map[map_y][map_x] != '1' \
	&& sets->map[map_y][map_x] != '2')
		sets->plr_x += dec;
}

void	change_y(t_sets *sets, int isdown)
{
	int map_x;
	int map_y;
	int dec;

	if (isdown)
		dec = 6;
	else
		dec = -6;
	map_x = sets->plr_x / 32;
	map_y = (sets->plr_y + dec) / 32;
	if (sets->map[map_y][map_x] && sets->map[map_y][map_x] != '1' \
	&& sets->map[map_y][map_x] != '2')
		sets->plr_y += dec;
}

int		cross_pressed(t_sets *sets)
{
	mlx_destroy_image(sets->wdw.mlx, sets->wdw.img);
	exit(0);
}

int		button_pressed(int key, t_sets *sets)
{
	mlx_clear_window(sets->wdw.mlx, sets->wdw.wdw);

	if (key == ESC_BUTTON)
	{
		// mlx_destroy_window(sets->mlx, sets->wdw);
		mlx_destroy_image(sets->wdw.mlx, sets->wdw.img);
		exit(0);
	}
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
	calc_map(sets);
	return (0);
}
