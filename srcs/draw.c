/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/16 09:15:24 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_sets *sets, int x, int y, int col)
{
	int temp_y;
	int temp_x;

	temp_y = y;
	while (temp_y < y + 50)
	{
		temp_x = x;
		while (temp_x < x + 50)
			mlx_pixel_put(sets->mlx, sets->wdw, temp_x++, temp_y, col);
		temp_y++;
	}
}

void	draw_line(t_sets *s, double coords[], int count)
{
	int last_y;

	last_y = coords[1] - count;
	// if s[y]
	while (last_y != coords[1])
		mlx_pixel_put(s->mlx, s->wdw, coords[0], coords[1]--, 0xC2171D);
}

void	draw_dir(t_sets *s, int x, int y)
{
	double	coords[2];
	double	dec_y;

	coords[0] = x * 50 + 50 / 2;
	coords[1] = y * 50 + 50 / 2;
	// mlx_pixel_put(s->mlx, s->wdw, coor_x, coor_y, 0xC2171D);
	return ;
	if (s->plr_d == M_PI / 2)
		dec_y = - 1;
	else if (s->plr_d == 3 * M_PI / 2)
		dec_y = 1;
	if (s->map[y][x] != '2' && s->map[y][x] != '1')
	{
		draw_line(s, coords, 25);
		y += dec_y;
	}
	while (s->map[y][x] && s->map[y][x] == '0')
	{
		draw_line(s, coords, 50);
		y += dec_y;
		// ft_putnbr_fd(x, 1);
		// ft_putchar_fd(' ', 1);
		// ft_putnbr_fd(y, 1);
		// ft_putendl_fd("", 1);
		// coords[1] -= 50;
		// y--;
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
			x += 50;
		}
		i++;
		y += 50;
	}
	// mlx_pixel_put(s->mlx, s->wdw, s->plr_x * 50 + 50 / 2, s->plr_y * 50 + 50 / 2, 0xC2171D);
	draw_dir(s, s->plr_x, s->plr_y);
	// draw_dir(s, s->plr_x * 50, s->plr_y * 50);
	// draw_square(s, s->plr_x * 50, s->plr_y * 50, 0xC2171D);
}

int		key_press(int key, t_sets *sets)
{
	mlx_clear_window(sets->mlx, sets->wdw);
	if (key == 53)
		exit(0);
		// mlx_destroy_window(sets->mlx, sets->wdw);
	else if (key == 123)
		ft_putendl_fd("left", 1);
	else if (key == 124)
		ft_putendl_fd("rigth", 1);
	else if (key == 13)
	{
		// sets->player_y += sin(sets->player_d)
		// sets->plr_y -= 0.1;
		sets->plr_y -= 1;
		ft_putendl_fd("W", 1);
	}
	else if (key == 1)
	{
		// sets->plr_y += 0.1;
		sets->plr_y += 1;
		ft_putendl_fd("S", 1);
	}
	else if (key == 0)
	{
		// sets->plr_x -= 0.1;
		sets->plr_x -= 1;
		ft_putendl_fd("A", 1);
	}
	else if (key == 2)
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
