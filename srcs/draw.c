/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/07 16:23:51 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(t_sets sets, int x, int y, int col)
{
	int temp_y;
	int temp_x;

	temp_y = y;
	while (temp_y < y + 50)
	{
		temp_x = x;
		while (temp_x < x + 50)
			mlx_pixel_put(sets.mlx, sets.wdw, temp_x++, temp_y, col);
		temp_y++;
	}
}

void	draw_2dmap(char **map, t_sets sets)
{
	int		x;
	int		y;
	int		i;
	int		j;

	y = 0;
	i = 9;
	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j])
		{
			if (map[i][j++] == '1')
				draw_square(sets, x, y, 0xFFFFFF);
			else if (map[i][j - 1] == 'N' || map[i][j - 1] == 'S' \
							|| map[i][j - 1] == 'E' || map[i][j - 1] == 'W')
				draw_square(sets, x, y, 0xC2171D);
			x += 50;
		}
		i++;
		y += 50;
	}
}
