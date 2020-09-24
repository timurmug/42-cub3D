/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:50:39 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/24 15:08:27 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_transparency(t_img texture, int index)
{
	if (texture.addr[index] == 0 && texture.addr[index + 1] == 0 && texture.addr[index + 2] == 0 && texture.addr[index + 3] == 0)
		return (0);
	return (1);
}

double	get_dir_sprite(t_sprite sprite, t_sets *s, double pov)
{
	double	sprite_dir;


	sprite_dir = atan2(sprite.y - s->plr_y, sprite.x - s->plr_x);
	while (sprite_dir - pov > M_PI)
		sprite_dir -= 2 * (double)M_PI;
	while (sprite_dir - pov < -M_PI)
		sprite_dir += 2 * (double)M_PI;
	// sprite_dir = ft_correct_angle(sprite_dir);
	return (sprite_dir);
}

void	calculate_offset(t_sprite *sprite, t_sets *s, double angle)
{
	double	fov = 60.f * (double)M_PI / 180;

	// angle = ft_correct_angle(angle);
	// fov = ft_correct_angle(fov);
	sprite->h_offset = (int)(angle * (double)s->wdw.r_x / fov + (double)s->wdw.r_x / 2 - (double)sprite->height / 2);
	sprite->v_offset = (int)(s->wdw.r_y / 2 - ((double)sprite->height / 2));
}
