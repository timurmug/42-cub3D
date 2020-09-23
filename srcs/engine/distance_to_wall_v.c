/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall_v.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:21:28 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/23 10:54:58 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_step_x_vertical(double angle)
{
	if ((angle <= M_PI / 2) || (angle >= 3 * M_PI / 2 && angle < 2 * M_PI))
		return (CELL);
	else
		return (-CELL);
}

double	get_x_vertical(double position, double angle)
{
	float	x;

	x = (double)((int)(position / SCALE) * SCALE);
	if ((angle <= M_PI / 2) || (angle >= 3 * M_PI / 2 && angle < 2 * M_PI))
		x += SCALE;
	else
		x -= .01f;
	return ((double)x);
}

double	get_y_vertical(t_sets *s, double x, double angle)
{
	return (s->plr_y + (s->plr_x - x) * tanf(angle));
}

t_dist	distance_to_wall_v(t_sets *s, double angle)
{
	const double	step_x = get_step_x_vertical(angle);
	const double	step_y = -step_x * tanf(angle);
	t_coords_double	current;
	t_coords_int	map;
	t_dist			dist;

	current.x = get_x_vertical(s->plr_x, angle);
	current.y = get_y_vertical(s, current.x, angle);
	map.x = (int)(current.x / SCALE);
	map.y = (int)(current.y / SCALE);
	while (map.y > 0 && map.y < s->map_size_y)
	{
		if (s->map[map.y][map.x] == '1' || s->map[map.y][map.x] == '2')
			break ;
		current.x += step_x;
		current.y += step_y;
		map.x = (int)(current.x / SCALE);
		map.y = (int)(current.y / SCALE);
	}
	dist.x = (current.x < 0) ? 0 : current.y; //get_texture_coordinate(current.y);
	dist.dist = sqrt(pow(s->plr_x - current.x, 2) + pow(s->plr_y - current.y, 2));
	// return (sqrt(pow(s->plr_x - current.x, 2) + pow(s->plr_y - current.y, 2)));
	return (dist);
}
