/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall_h.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:22:09 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/21 16:22:33 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_y_horizontal(t_sets *s, double angle)
{
	double	y;

	y = (double)((int)(s->plr_y / SCALE) * SCALE);
	y += (angle < M_PI) ? -.01f : SCALE;
	return (y);
}

int		distance_to_wall_h(t_sets *s, double angle)
{
	const double	step_y = (angle < M_PI) ? -SCALE : SCALE;
	const double	step_x = -step_y * (1 / tanf(angle));
	double			current_x;
	double			current_y;

	current_y = get_y_horizontal(s, angle);
	current_x = s->plr_x + (s->plr_y - current_y) * (1 / tanf(angle));
	while (s->map[(int)current_y / SCALE][(int)current_x / SCALE] &&\
	s->map[(int)current_y / SCALE][(int)current_x / SCALE] != '1' && \
	s->map[(int)current_y / SCALE][(int)current_x / SCALE] != '2')
	{
		current_x += step_x;
		current_y += step_y;
	}
	return (sqrt(pow(s->plr_x - current_x, 2) + pow(s->plr_y - current_y, 2)));
}
