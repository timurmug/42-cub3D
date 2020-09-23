/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:02 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/23 09:25:26 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling_floor(t_sets *s, int x, double wall_y, int isceil)
{
	double temp_y;

	if (isceil)
	{
		temp_y = 0;
		if (wall_y > 0)
			while (temp_y < wall_y)
				pixel_put(s, x, temp_y++, s->ceiling_col);
	}
	else if (wall_y <= s->wdw.r_y)
		while (wall_y <= s->wdw.r_y)
			pixel_put(s, x, wall_y++, s->floor_col);
}

void	draw_column(t_sets *s, int wall_x, double degree, double ray, int color)
{
	double	height;
	double	wall_y;

	ray *= cos(s->plr_d - degree);
	height = (SCALE / ray) * ((double)s->wdw.r_x / 2 / tan(FOV_HALF));
	wall_y = s->wdw.r_y / 2 - height / 2;

	draw_ceiling_floor(s, wall_x, wall_y, 1);
	if (height >= s->wdw.r_y)
		height = s->wdw.r_y;
	if (wall_y < 0)
		wall_y = 0;
	while (height-- > 0)
	{
		if (wall_y < s->wdw.r_y)
		{
			pixel_put(s, wall_x, wall_y, color);
			wall_y++;
		}
	}
	draw_ceiling_floor(s, wall_x, wall_y, 0);
}
