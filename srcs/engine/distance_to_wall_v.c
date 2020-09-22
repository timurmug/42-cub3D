/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall_v.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:21:28 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/22 15:20:09 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double		get_step_x_vertical(double angle)
{
	if ((angle <= M_PI / 2) || (angle >= 3 * M_PI / 2 && angle < 2 * M_PI))
		return (CELL);
	else
		return (-CELL);
}

double		get_x_vertical(double position, double angle)
{
	float	x;

	x = (double)((int)(position / SCALE) * SCALE);
	if ((angle <= M_PI / 2) || (angle >= 3 * M_PI / 2 && angle < 2 * M_PI))
		x += SCALE;
	else
		x -= .01f;
	return ((double)x);
}

double		get_y_vertical(t_sets *s, double x, double angle)
{
	return (s->plr_y + (s->plr_x - x) * tanf(angle));
}

double	distance_to_wall_v(t_sets *s, double angle)
{
	const double	step_x = get_step_x_vertical(angle);
	const double	step_y = -step_x * tanf(angle);
	double			current_x;
	double			current_y;
	int				map_x;
	int				map_y;
	int				max_y;

	current_x = get_x_vertical(s->plr_x, angle);
	current_y = get_y_vertical(s, current_x, angle);
	map_x = (int)(current_x / SCALE);
	map_y = (int)(current_y / SCALE);
	max_y = ft_strstrlen(s->map);
	while (map_y > 0 && map_y < max_y)
	{
		if (s->map[map_y][map_x] == '1' || s->map[map_y][map_x] == '2')
			break ;
		current_x += step_x;
		current_y += step_y;
		map_x = (int)(current_x / SCALE);
		map_y = (int)(current_y / SCALE);
	}
	return (sqrt(pow(s->plr_x - current_x, 2) + pow(s->plr_y - current_y, 2)));
}
