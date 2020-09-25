/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 09:51:34 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 10:05:28 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include <stdio.h>
void	put_sprite(t_sprite sprite, t_sets *s, t_img img, int i)
{
 	const t_img	texture = sprite.txtr.img_data;
	int			index_texture;
	int			index;
	int			x;

	x = 0;
	while (x < sprite.height)
	{
		if (sprite.v_offset + x > 0 && sprite.v_offset + x <= s->wdw.r_y)
		{
			printf("%do\n", img.size_line);
			index = (sprite.v_offset + x) * img.size_line + (sprite.h_offset + i) * img.bpp / 8;
			index_texture = x * texture.height / sprite.height * texture.size_line + i * texture.height / sprite.height * img.bpp / 8;
			if (check_transparency(texture, index_texture))
			{
				put_pixel_img(img, texture, index, index_texture);
			}
		}
		x++;
	}
}

void	rendering_sprite(t_sprite item, t_sets *s, const double *distances)
{
	const t_img	img = s->wdw.img_data;
	int			y;

	y = 0;
	while (y < item.height)
	{
		if ((item.h_offset + y > 0 && item.h_offset + y <= s->wdw.r_x) && (distances[item.h_offset + y] > item.dist * 0.9))
			put_sprite(item, s, img, y);
		y++;
	}
}

void	sorting_sprites(t_sprite *items, int number_items)
{
	t_sprite	temp_item;
	int			n;
	int			i;
	int			flag;

	n = 0;
	while (n < number_items)
	{
		i = 0;
		flag = 0;
		while (i < number_items - n)
		{
			if ((i + 1) < number_items && items[i].dist < items[i + 1].dist)
			{
				temp_item = items[i];
				items[i] = items[i + 1];
				items[i + 1] = temp_item;
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		return ;
		n++;
	}
}

double	calculate_height(double distance_to_wall, t_sets *s)
{
	double			height;

	height = (SCALE / distance_to_wall) * ((double)s->wdw.r_x / 2 / tan(FOV_HALF));
	return (height);
}

void	sprites_init(t_sets *s)
{
	const double	pov = -(s->plr_d);
	double			dir_sprite;
	t_sprite		*sprite;
	int				count;

	count = 0;
	while (count < s->count_sprts)
	{
		sprite = &s->sprites[count];
		dir_sprite = get_dir_sprite(*sprite, s, pov);
		sprite->dist = sqrt(pow(s->plr_x - sprite->x, 2) + pow(s->plr_y - sprite->y, 2));
		sprite->height = (int)calculate_height(sprite->dist, s);
		calculate_offset(sprite, s, dir_sprite - pov);
		count++;
	}
}

void	draw_sprites(t_sets *s, double *distances)
{
	t_sprite	sprite;
	int			count;

	sprites_init(s);
	sorting_sprites(s->sprites, s->count_sprts);
	count = 0;
	while (count < s->count_sprts)
	{
		sprite = s->sprites[count];
		rendering_sprite(sprite, s, distances);
		count++;
	}
}
