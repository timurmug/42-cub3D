/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:25:18 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 09:03:00 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pixel_put(t_sets *s, int x, int y, int color)
{
    char    *dst;

    dst = s->wdw.img_data.addr + (y * s->wdw.img_data.size_line + \
		x * (s->wdw.img_data.bpp / 8));
    *(unsigned int*)dst = color;
}

void	put_pixel_img(t_img img, t_img texture,
		int index, int index_texture)
{
	img.addr[index] = texture.addr[index_texture];
	img.addr[index + 1] = texture.addr[index_texture + 1];
	img.addr[index + 2] = texture.addr[index_texture + 1];
	img.addr[index + 3] = texture.addr[index_texture + 1];
}

double	ft_correct_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	else if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

t_dist	dist_to_wall_init(t_dist dist_to_wall, double pov, double angle)
{
	t_dist	dist;

	dist.x = modf(dist_to_wall.x / SCALE, &dist_to_wall.x);
	dist.dist = dist_to_wall.dist * cos(pov - angle);
	return (dist);
}

t_dist	get_dist_and_texture(t_sets *s, double angle)
{
	t_dist dist1;
	t_dist dist2;

	dist1 = distance_to_wall_h(s, angle);
	dist2 = distance_to_wall_v(s, angle);
	if (dist1.dist < dist2.dist)
	{
		if (angle < M_PI)
			s->curr_txtr.img_data = s->n_txtr.img_data;
		else
			s->curr_txtr.img_data = s->s_txtr.img_data;
		return (dist_to_wall_init(dist1, s->plr_d, angle));
	}
	else
	{
		if (angle > M_PI / 2 && angle < M_PI * 3 / 2)
			s->curr_txtr.img_data = s->w_txtr.img_data;
		else
			s->curr_txtr.img_data = s->e_txtr.img_data;
		return (dist_to_wall_init(dist2, s->plr_d, angle));
	}
}
