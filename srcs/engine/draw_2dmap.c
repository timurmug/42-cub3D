/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:16:08 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/27 11:30:20 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			draw_square(t_sets *sets, int x, int y, int col)
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

int				get_begin_map(t_sets *s)
{
	char	**splitted;
	int		i;

	i = 0;
	while (s->map[i])
	{
		if (!(splitted = ft_split(s->map[i], ' ')))
		{
			ft_putendl_fd(SMTH_ERR, 1);
			close_mlx(s);
		}
		if (!ft_strstrlen(splitted))
		{
			i++;
			ft_free_strstr(splitted);
		}
		else
		{
			ft_free_strstr(splitted);
			break ;
		}
	}
	return (i);
}

void			draw_plr(t_sets *s, int i_start)
{
	t_coords_int	plr;
	int				scale_map;

	scale_map = s->wdw.r_x * s->wdw.r_y / 129600;
	plr.y = (s->plr_y) / SCALE;
	plr.x = (s->plr_x) / SCALE;
	draw_square(s, (int)(scale_map + plr.x * scale_map), \
	(int)(scale_map + plr.y * scale_map - i_start * scale_map), \
	0xef614a);
}

void			draw_2dmap(t_sets *s, int scale_map)
{
	t_coords_int	map_scale;
	int				i;
	int				j;
	int				i_start;

	map_scale.y = scale_map;
	i = get_begin_map(s);
	i_start = i;
	while (s->map[i])
	{
		j = 0;
		map_scale.x = scale_map;
		while (s->map[i][j])
		{
			if (s->map[i][j++] == '1')
				draw_square(s, map_scale.x, map_scale.y, 0xFFFFFF);
			else if (s->map[i][j - 1] == '2')
				draw_square(s, map_scale.x, map_scale.y, 0x6AA84F);
			draw_plr(s, i_start);
			map_scale.x += scale_map;
		}
		i++;
		map_scale.y += scale_map;
	}
}
