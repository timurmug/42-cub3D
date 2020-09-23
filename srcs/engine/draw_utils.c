/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:25:18 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/23 10:37:11 by qtamaril         ###   ########.fr       */
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
	img.addr[index + 2] = texture.addr[index_texture + 2];
	img.addr[index + 3] = texture.addr[index_texture + 3];
}

double	ft_correct_angle(double angle)
{
	if (angle < 0)
	angle += 2 * M_PI;
	else if (angle >= 2 * M_PI)
	angle -= 2 * M_PI;
	return (angle);
}

void	get_wall_texture(t_sets *s, double angle, double distance_to_wall_h, \
	double distance_to_wall_v)
{
	if (distance_to_wall_h < distance_to_wall_v)
	{
		if (angle < M_PI)
			s->curr_txtr.img_data = s->n_txtr.img_data; //смотрю с юга
		else
			s->curr_txtr.img_data = s->s_txtr.img_data; //смотрю с cевера
	}
	else
	{
		if (angle > M_PI / 2 && angle < M_PI * 3 / 2)
			s->curr_txtr.img_data = s->w_txtr.img_data; //смотрю с востока
		else
			s->curr_txtr.img_data = s->e_txtr.img_data; //смотрю с запада
	}
}
