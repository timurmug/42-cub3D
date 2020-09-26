/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:16:08 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 13:14:09 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(t_sets *sets, int x, int y, int col)
{
	t_coords_int	temp;
	int				scale_map;

	temp.y = y;
	scale_map = sets->wdw.r_x * sets->wdw.r_y / 129600;
	while (temp.y < y + scale_map)
	{
		temp.x = x;
		while (temp.x < x + scale_map)
			pixel_put(sets, temp.x++, temp.y, col);
		temp.y++;
	}
}

int		get_begin_map(t_sets *s)
{
	int		i;

	i = 0;
	while (s->map[i])
	{
		if (!ft_strstrlen(ft_split(s->map[i], ' ')))
			i++;
		else
			break;
	}
	return (i);
}

void	draw_2dmap(t_sets *s, int scale_map)
{
	t_coords_int map_scale;
	int		i;
	int		j;
	int		i_start;

	map_scale.y = scale_map;
	i = get_begin_map(s);
	i_start = i;
	while (s->map[i])
	{
		j = 0;
		map_scale.x = scale_map;
		while (s->map[i][j])
		{
			int plr_y = (s->plr_y) / SCALE;
			int plr_x = (s->plr_x) / SCALE;
			if (s->map[i][j++] == '1')
				draw_square(s, map_scale.x, map_scale.y, 0xFFFFFF);
			else if (s->map[i][j - 1] == '2')
				draw_square(s, map_scale.x, map_scale.y, 0x6AA84F);
			draw_square(s, (int)(scale_map + plr_x * scale_map), (int)(scale_map + plr_y * scale_map - i_start * scale_map), 0xef614a);
			map_scale.x += scale_map;
		}
		i++;
		map_scale.y += scale_map;
	}
}
