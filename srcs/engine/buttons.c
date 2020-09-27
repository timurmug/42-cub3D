/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:30:13 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/27 10:42:04 by qtamaril         ###   ########.fr       */
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
	else if (sets->plr_d > 2 * M_PI)
		sets->plr_d -= 2 * M_PI;
}

int		check_wall(t_sets *sets, double step_x, double step_y, int mov_speed)
{
	int	coord_x;
	int	coord_y;

	coord_x = (int)((sets->plr_x + step_x * mov_speed * 2) / 64);
	coord_y = (int)((sets->plr_y + step_y * mov_speed * 2) / 64);
	return (sets->map[coord_y][coord_x] != '1' &&
			sets->map[coord_y][coord_x] != '2');
}

void	change_position(int key, t_sets *sets)
{
	const double coss = cosf(sets->plr_d);
	const double sinn = -sinf(sets->plr_d);

	if (key == W_BUTTON && check_wall(sets, coss, sinn, MOV_SPEED + 2))
	{
		sets->plr_x += coss * (MOV_SPEED + 2);
		sets->plr_y += sinn * (MOV_SPEED + 2);
	}
	else if (key == S_BUTTON && check_wall(sets, -coss, -sinn, MOV_SPEED + 2))
	{
		sets->plr_x -= coss * (MOV_SPEED + 2);
		sets->plr_y -= sinn * (MOV_SPEED + 2);
	}
	else if (key == D_BUTTON && check_wall(sets, -sinn, coss, MOV_SPEED))
	{
		sets->plr_x -= sinn * MOV_SPEED;
		sets->plr_y += coss * MOV_SPEED;
	}
	else if (key == A_BUTTON && check_wall(sets, sinn, -coss, MOV_SPEED))
	{
		sets->plr_x += sinn * MOV_SPEED;
		sets->plr_y -= coss * MOV_SPEED;
	}
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
	else if (key == A_BUTTON || key == D_BUTTON || key == S_BUTTON || \
		key == W_BUTTON)
		change_position(key, sets);
	draw_img(sets, 0);
	return (0);
}
