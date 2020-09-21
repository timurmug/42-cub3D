/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall_v.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:21:28 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/21 18:35:53 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_step_x_vertical(double angle)
{
	if (angle < (M_PI / 2) || angle > (3 * M_PI / 2))
		return (SCALE);
	else
		return (-SCALE);
}

double	get_x_vertical(double position, double angle)
{
	double	x;

	x = (int)(position / SCALE) * SCALE;
	x += (angle < (M_PI / 2) || angle > (3 * M_PI / 2)) ? SCALE : - 1;
	return (x);
}

int		get_y_max(t_sets *s, double	current_y, double current_x)
{
	int max_y = 0;

	max_y = (int)current_y;
	while (s->map[max_y][(int)current_x])
		max_y++;
	return (max_y);
}

double	get_texture_coordinate(double current_x)
{
	if (current_x < 0)
		return (0);
	return (current_x);
}

#include <stdio.h>
int		distance_to_wall_v(t_sets *s, double angle)
{
	const double	step_x = get_step_x_vertical(angle);
	const double	step_y = -step_x * tanf(angle);
	double			current_x;
	double			current_y;
	int				max_y;

	current_x = get_x_vertical(s->plr_x, angle);
	current_y = s->plr_y + (s->plr_x - current_x) * tanf(angle);
	// printf("%d %d\n", (int)current_y / SCALE, (int)current_x / SCALE);
	// return (1);
	current_x /= SCALE;
	current_y /= SCALE;
	current_x = (int)current_x;
	current_y = (int)current_y;
	// max_y = get_y_max(s, current_y, current_x);
	max_y = ft_strstrlen(s->map);
	// printf("%d\n", max_y);
	// return (1);
	while (current_y > 0 && current_y < max_y)
	{
		if (s->map[(int)current_y][(int)current_x] == '1')
			break ;
		current_x += step_x;
		current_y += step_y;
		current_x /= SCALE;
		current_y /= SCALE;
		current_x = (int)current_x;
		current_y = (int)current_y;
	}
	printf("%d %d \n", (int)current_y, (int)current_x);

	// return (1);
	return (sqrt(pow(s->plr_x - current_x, 2) + pow(s->plr_y - current_y, 2)));

}
