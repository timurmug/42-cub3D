/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall_h.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:22:09 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/22 15:20:17 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double		get_x_horizontal(t_sets *s, double y, double angle)
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

double	distance_to_wall_h(t_sets *s, double angle)
{
	const double	step_y = (angle <= M_PI && angle >= 0) ? -SCALE : SCALE;
	const double	step_x = -step_y * (1 / tanf(angle));
	double			current_x;
	double			current_y;
	int				map_x;
	int				map_y;

	current_y = get_y_horizontal(s->plr_y, angle);
	current_x = get_x_horizontal(s, current_y, angle);
	map_x = (int)(current_x / SCALE);
	map_y = (int)(current_y / SCALE);
	while (map_x > 0 && map_x < (int)ft_strlen(s->map[map_y]))
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
