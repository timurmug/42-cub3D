/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:16:08 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 11:33:18 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(t_sets *sets, int x, int y, int col)
{
	int temp_y;
	int temp_x;

	temp_y = y;
	// while (temp_y < y + SCALE / 4)
	while (temp_y < y + SCALE / 4)
	{
		temp_x = x;
		while (temp_x < x + SCALE / 4)
			// mlx_pixel_put(sets->wdw.mlx, sets->wdw.wdw, temp_x++, temp_y, col);
			pixel_put(sets, temp_x++, temp_y, col);
		temp_y++;
	}
}

#include <stdio.h> ///sfsdf
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
			int plr_y = (s->plr_y - SCALE / 2) / SCALE;
			int plr_x = (s->plr_x - SCALE / 2) / SCALE;
			// printf("plr_y: %d plr_x: %d\n", plr_y, plr_x);
			// int plr_x = ;
			if (s->map[i][j++] == '1')
				draw_square(s, x, y, 0xFFFFFF);
			else if (s->map[i][j - 1] == '2')
				draw_square(s, x, y, 0x6AA84F);
			// else if (s->map[plr_y][plr_x] == 'N')
				// draw_square(s, plr_x * SCALE / 4, plr_y * SCALE / 4, 0xef614a);
				pixel_put(s, plr_x * SCALE / 4, plr_y * SCALE / 4, 0xef614a);
			x += SCALE / 4;
		}
		i++;
		y += SCALE / 4;
	}
}
