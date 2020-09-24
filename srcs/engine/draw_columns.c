/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:02 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/24 09:49:49 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling_floor(t_sets *s, int x, double wall_y, int isceil)
{
	double temp_y;

	if (isceil)
	{
		temp_y = 0;
		if (wall_y > 0)
			while (temp_y < wall_y)
				pixel_put(s, x, temp_y++, s->ceiling_col);
	}
	else if (wall_y <= s->wdw.r_y)
		while (wall_y <= s->wdw.r_y)
			pixel_put(s, x, wall_y++, s->floor_col);
}

double	draw_wall(t_sets *s, int wall_x, int wall_y, int height)
{
	const t_img	img = s->wdw.img_data;
	t_txtr		txtr;
	double		txtr_position;
	int			index;
	int			index_texture;

	txtr = s->curr_txtr;
	txtr.step = 1.0f * (double)txtr.img_data.height / (double)height;
	txtr.x *= (txtr.img_data.bpp / 8);
	wall_x *= img.bpp / 8;
	txtr_position = ((double)wall_y - (double)s->wdw.r_y / 2 + \
	(double)height / 2) * txtr.step;
	while (height-- > 0)
	{
		txtr.y = (int)txtr_position & (txtr.img_data.height - 1);
		index_texture = txtr.y * txtr.img_data.size_line + txtr.x;
		index = wall_y * img.size_line + wall_x;
		if (index >= img.size_line * s->wdw.r_y)
			break ;
		put_pixel_img(img, txtr.img_data, index, index_texture);
		txtr_position += txtr.step;
		wall_y++;
	}
	return (wall_y);
}

void	draw_column(t_sets *s, int wall_x, double ray)
{
	double	height;
	double	wall_y;

	height = (SCALE / ray) * ((double)s->wdw.r_x / 2 / tan(FOV_HALF));
	wall_y = s->wdw.r_y / 2 - height / 2;
	draw_ceiling_floor(s, wall_x, wall_y, 1);
	if (wall_y < 0)
		wall_y = 0;
	wall_y = draw_wall(s, wall_x, (int)wall_y, (int)height);
	if (height >= s->wdw.r_y)
		height = s->wdw.r_y;
	draw_ceiling_floor(s, wall_x, wall_y, 0);
}
