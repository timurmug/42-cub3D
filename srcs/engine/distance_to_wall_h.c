/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall_h.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:22:09 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/22 11:41:15 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double		get_x_horizontal(t_sets *s, double y, double angle)
{
	return (s->plr_x + (s->plr_y - y) * (1 / tanf(angle)));
}

double	get_y_horizontal(t_sets *s, double angle)
{
	float	y;

	y = (float)((int)(s->plr_y / SCALE) * SCALE);
	y += (angle < M_PI) ? -.01f : SCALE;
	return ((double)y);
}

// int		get_max_y(t_sets *s)
// {
// 	int	y;
// 	int	max;
// 	int	len;
//
// 	y = 0;
// 	max = 0;
// 	while (s->map[y])
// 	{
// 		len = ft_strlen(s->map[y++]);
// 		if (len > max)
// 			max = len;
// 	}
// 	return (max);
// }

double	distance_to_wall_h(t_sets *s, double angle)
{
	const double	step_y = (angle < M_PI) ? -SCALE : SCALE;
	const double	step_x = -step_y * (1 / tanf(angle));
	double			current_x;
	double			current_y;
	int				map_x;
	int				map_y;
	// int				max_x;

	current_y = get_y_horizontal(s, angle);
	current_x = get_x_horizontal(s, current_y, angle);
	map_x = (int)(current_x / SCALE);
	map_y = (int)(current_y / SCALE);

	// while (s->map[map_y][map_x] &&\
	// s->map[map_y][map_x] != '1' && \
	// s->map[map_y][map_x] != '2')
	// max_x = get_max_y(s);
	// ft_putnbr_fd(max_x, 1);
	// ft_putchar_fd('\n', 1);
	// return (1);
	// while (map_x > 0 && map_x < max_x)
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
