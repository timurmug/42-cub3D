/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:15:59 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/24 11:50:57 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_sprite	init_sprite_coord(int x, int y, t_sets *sets)
{
	t_sprite	sprite;

	sprite.x = (double)x + SCALE;
	sprite.y = (double)y + SCALE;
	sprite.txtr.img_data = sets->sprt_txtr.img_data;
	return (sprite);
}

void	count_sprites(t_sets *sets)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (sets->map[i])
	{
		j = 0;
		while (sets->map[i][j])
			if (sets->map[i][j++] == '2')
			{
				sets->count_sprts++;
			}
		i++;
	}
}

void	get_sprites(t_sets *sets)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count_sprites(sets);
	i = 0;
	count = 0;

	sets->sprites = ft_calloc(sets->count_sprts + 1, sizeof(t_sprite));
	while (sets->map[i])
	{
		j = 0;
		while (sets->map[i][j])
			if (sets->map[i][j++] == '2')
			{
				sets->sprites[count] = init_sprite_coord(j, i, sets);
				count++;
			}
		i++;
	}
}
