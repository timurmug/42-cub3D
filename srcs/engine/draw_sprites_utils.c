/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:50:39 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 12:07:13 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


#include <stdio.h> //sasdaszdsadasd
int		check_transparency(t_img texture, int index)
{
	// printf("1: |%d| 2: |%d| 3: |%d| 4 |%d|\n", texture.addr[index], texture.addr[index + 1], texture.addr[index + 2], texture.addr[index + 3]);

	if (texture.addr[index] == 0 && texture.addr[index + 1] == 0 && texture.addr[index + 2] == 0 && texture.addr[index + 3] == 0)
	// if (texture.addr[index] <= 0 && texture.addr[index + 1] == 0 && texture.addr[index + 2] == 0 && texture.addr[index + 3] <= 0)
	// if (texture.addr[index] == 0 && texture.addr[index + 1] == 0 && texture.addr[index + 2] == 0)
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
	return (sprite_dir);
}

void	calculate_offset(t_sprite *sprite, t_sets *s, double angle)
{
	double	fov = 60.f * (double)M_PI / 180;

	sprite->h_offset = (int)(angle * (double)s->wdw.r_x / fov + (double)s->wdw.r_x / 2 - (double)sprite->height / 2);
	sprite->v_offset = s->wdw.r_y / 2 - ((double)sprite->height / 2);
}
