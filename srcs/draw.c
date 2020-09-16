/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/16 13:47:04 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_sets *sets, int x, int y, int col)
{
	int temp_y;
	int temp_x;

	temp_y = y;
	while (temp_y < y + SCALE)
	{
		temp_x = x;
		while (temp_x < x + SCALE)
			mlx_pixel_put(sets->mlx, sets->wdw, temp_x++, temp_y, col);
		temp_y++;
	}
}

void	draw_line(t_sets *s)
{
	float	step_x;
	float	step_y;
	float	current_x;
	float	current_y;

	step_x = cos(s->plr_d);
	step_y = -sin(s->plr_d);
	current_x = s->plr_x;
	current_y = s->plr_y;
	while (s->map[(int)current_y / SCALE][(int)current_x / SCALE] &&\
	s->map[(int)current_y / SCALE][(int)current_x / SCALE] != '1' && \
	s->map[(int)current_y / SCALE][(int)current_x / SCALE] != '2')
	{
		mlx_pixel_put(s->mlx, s->wdw, current_x, current_y, 0xC2171D);
		current_x += step_x;
		current_y += step_y;
		// temp_x += dec;
		// map_x = temp_x / 32;
	}
}

void	draw_2dmap(t_sets *s)
{
	int		x;
	int		y;
	int		i;
	int		j;

	y = 0;
	i = 0;
	while (s->map[i])
	{
		j = 0;
		x = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j++] == '1')
				draw_square(s, x, y, 0xFFFFFF);
			else if (s->map[i][j - 1] == '2')
				draw_square(s, x, y, 0x6AA84F);
			x += SCALE;
		}
		i++;
		y += SCALE;
	}
	draw_line(s);
}

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

int		key_press(int key, t_sets *sets)
{
	mlx_clear_window(sets->mlx, sets->wdw);
	if (key == ESC_BUTTON)
		exit(0);
		// mlx_destroy_window(sets->mlx, sets->wdw);
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
	draw_2dmap(sets);
	return (0);
}
int ft_exit(t_sets *sets)
{
	(void)sets;
	exit(0);
}
void	create_window(t_sets sets)
{
	sets.wdw = mlx_new_window(sets.mlx, sets.r_x, sets.r_y, "cub3d");
	draw_2dmap(&sets);
	// mlx_key_hook(sets.wdw, key_press, &sets);
	mlx_hook(sets.wdw, 2, 1L<<0, key_press, &sets);
	mlx_hook(sets.wdw, 17, 1L<<0, ft_exit, &sets);

	mlx_loop(sets.mlx);
}
