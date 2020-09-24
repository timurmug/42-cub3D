/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall_h.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:22:09 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/24 10:02:14 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_x_horizontal(t_sets *s, double y, double angle)
{
	return (s->plr_x + (s->plr_y - y) * (1 / tanf(angle)));
}

double	get_y_horizontal(double position, double angle)
{
	float	y;

	y = (double)((int)(position / SCALE) * SCALE);
	y += (angle <= M_PI && angle >= 0) ? -.01f : SCALE;
	return ((double)y);
}

t_dist	distance_to_wall_h(t_sets *s, double angle)
{
	const double	step_y = (angle <= M_PI && angle >= 0) ? -SCALE : SCALE;
	const double	step_x = -step_y * (1 / tanf(angle));
	t_coords_double	current;
	t_coords_int	map;
	t_dist			dist;

	current.y = get_y_horizontal(s->plr_y, angle);
	current.x = get_x_horizontal(s, current.y, angle);
	map.x = (int)(current.x / SCALE);
	map.y = (int)(current.y / SCALE);
	while (map.x > 0 && map.x < (int)ft_strlen(s->map[map.y]))
	{
		if (s->map[map.y][map.x] == '1')
			break ;
		current.x += step_x;
		current.y += step_y;
		map.x = (int)(current.x / SCALE);
		map.y = (int)(current.y / SCALE);
	}
	dist.x = (current.x < 0) ? 0 : current.x;
	dist.dist = sqrt(pow(s->plr_x - current.x, 2) + pow(s->plr_y - current.y, 2));
	return (dist);
}
