/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/16 11:13:28 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_sets *sets, int x, int y, int col)
{
	int temp_y;
	int temp_x;

	temp_y = y;
	while (temp_y < y + 32)
	{
		temp_x = x;
		while (temp_x < x + 32)
			mlx_pixel_put(sets->mlx, sets->wdw, temp_x++, temp_y, col);
		temp_y++;
	}
}

void	draw_line_vert(t_sets *s, int dec)
{
	int	map_x;
	int	map_y;
	int	temp_y;

	temp_y = s->plr_y;
	map_x = s->plr_x / 32;
	map_y = temp_y / 32;
	while (s->map[map_y][map_x] && s->map[map_y][map_x] != '1' \
	&& s->map[map_y][map_x] != '2')
	{
		mlx_pixel_put(s->mlx, s->wdw, s->plr_x, temp_y, 0xC2171D);
		temp_y += dec;
		map_y = temp_y / 32;
	}
}

void	draw_line_hor(t_sets *s, int dec)
{
	int	map_x;
	int	map_y;
	int	temp_x;

	temp_x = s->plr_x;
	map_x = temp_x/ 32;
	map_y = s->plr_y / 32;
	while (s->map[map_y][map_x] && s->map[map_y][map_x] != '1' \
	&& s->map[map_y][map_x] != '2')
	{
		mlx_pixel_put(s->mlx, s->wdw, temp_x, s->plr_y, 0xC2171D);
		temp_x += dec;
		map_x = temp_x / 32;
	}
}

void	draw_line(t_sets *s)
{
	if (s->plr_d == M_PI / 2)
		draw_line_vert(s, -1);
	else if (s->plr_d == 3 * M_PI / 2)
		draw_line_vert(s, 1);
	else if (s->plr_d == M_PI)
		draw_line_hor(s, -1);
	else if (s->plr_d == 0)
		draw_line_hor(s, 1);
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
			x += 32;
		}
		i++;
		y += 32;
	}
	draw_line(s);
}

void	change_dir(t_sets *sets, int isleft)
{
	if (isleft)
		sets->plr_d += M_PI / 2;
	else
		sets->plr_d -= M_PI / 2;
	if (sets->plr_d < 0)
		sets->plr_d += 2 * M_PI;
	else if (sets->plr_d >= 2 * M_PI)
		sets->plr_d -= 2 * M_PI;
}

int		key_press(int key, t_sets *sets)
{
	mlx_clear_window(sets->mlx, sets->wdw);
	if (key == ESC_BUTTON)
		exit(0);
		// mlx_destroy_window(sets->mlx, sets->wdw);
	else if (key == LEFT_BUTTON)
	{
		change_dir(sets, 1);
		ft_putendl_fd("left", 1);
	}
	else if (key == RIGHT_BUTTON)
	{
		change_dir(sets, 0);
		ft_putendl_fd("rigth", 1);
	}
	else if (key == W_BUTTON)
	{
		sets->plr_y -= 1;
		ft_putendl_fd("W", 1);
	}
	else if (key == S_BUTTON)
	{
		sets->plr_y += 1;
		ft_putendl_fd("S", 1);
	}
	else if (key == A_BUTTON)
	{
		sets->plr_x -= 1;
		ft_putendl_fd("A", 1);
	}
	else if (key == D_BUTTON)
	{
		// sets->plr_x += 0.1;
		sets->plr_x += 1;
		ft_putnbr_fd(sets->plr_x, 1);
		ft_putendl_fd("D", 1);
	}
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
