/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:30:13 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 09:42:17 by qtamaril         ###   ########.fr       */
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

void	check_wall(t_sets *sets, int dec_x, int dec_y)
{
	int map_x;
	int map_y;

	map_x = (sets->plr_x + dec_x) / SCALE;
	map_y = (sets->plr_y + dec_y) / SCALE;
	if (sets->map[map_y][map_x] && sets->map[map_y][map_x] != '1' && sets->map[map_y][map_x] && sets->map[map_y][map_x] != '2')
	{
		sets->plr_y += dec_y;
		sets->plr_x += dec_x;
	}
}

void	change_x(t_sets *sets, int isright)
{
	int dec_x;
	int dec_y;

	if (isright)
	{
		dec_y = -sin(sets->plr_d - M_PI / 2) * MOV_SPEED;
		dec_x = cos(sets->plr_d - M_PI / 2) * MOV_SPEED;
	}
	else
	{
		dec_y = sin(sets->plr_d - M_PI / 2) * MOV_SPEED;
		dec_x = -cos(sets->plr_d - M_PI / 2) * MOV_SPEED;
	}
	check_wall(sets, dec_x, dec_y);
}

void	change_y(t_sets *sets, int isdown)
{
	int dec_x;
	int dec_y;

	if (isdown)
	{
		dec_y = sin(sets->plr_d) * 10;
		dec_x = -cos(sets->plr_d) * 10;
	}
	else
	{
		dec_y = -sin(sets->plr_d) * 10;
		dec_x = cos(sets->plr_d) * 10;
	}
	check_wall(sets, dec_x, dec_y);
}

int		cross_pressed(t_sets *sets)
{
	mlx_destroy_image(sets->wdw.mlx, sets->wdw.img_data.img);
	mlx_destroy_image(sets->wdw.mlx, sets->n_txtr.img_data.img);
	mlx_destroy_image(sets->wdw.mlx, sets->s_txtr.img_data.img);
	mlx_destroy_image(sets->wdw.mlx, sets->w_txtr.img_data.img);
	mlx_destroy_image(sets->wdw.mlx, sets->e_txtr.img_data.img);
	mlx_destroy_image(sets->wdw.mlx, sets->sprt_txtr.img_data.img);
	mlx_destroy_window(sets->wdw.mlx, sets->wdw.wdw);
	free(sets->map);
	free(sets->sprites);
	exit(0);
}

int		button_pressed(int key, t_sets *sets)
{
	mlx_clear_window(sets->wdw.mlx, sets->wdw.wdw);

	if (key == ESC_BUTTON)
		return (cross_pressed(sets));
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
	draw_img(sets);
	return (0);
}
