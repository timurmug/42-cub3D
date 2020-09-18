/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:16:08 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/18 15:37:56 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(t_sets *sets, int x, int y, int col)
{
	int temp_y;
	int temp_x;

	temp_y = y;
	while (temp_y < y + SCALE)
	{
		temp_x = x;
		while (temp_x < x + SCALE)
			mlx_pixel_put(sets->wdw.mlx, sets->wdw.wdw, temp_x++, temp_y, col);
		temp_y++;
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
}
