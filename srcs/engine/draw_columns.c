/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:02 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/23 11:33:39 by qtamaril         ###   ########.fr       */
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

#include <stdio.h>
void	draw_column(t_sets *s, int wall_x, double degree, double ray, int color)
{
	double	height;
	double	wall_y;

	ray *= cos(s->plr_d - degree);
	height = (SCALE / ray) * ((double)s->wdw.r_x / 2 / tan(FOV_HALF));
	wall_y = s->wdw.r_y / 2 - height / 2;

	draw_ceiling_floor(s, wall_x, wall_y, 1);
	if (height >= s->wdw.r_y)
		height = s->wdw.r_y;
	if (wall_y < 0)
		wall_y = 0;

	(void)color;
	// int	index;
	// int	index_texture;
	t_txtr txtr = s->curr_txtr;
	txtr.step = 1.0f * (double)txtr.img_data.height / (double)height;
	// ft_putnbr_fd(txtr.step, 1);
	// printf("%lf\n", txtr.step);
	txtr.x *= (txtr.img_data.bpp / 8);
	wall_x *= (s->wdw.img_data.bpp / 8);
	printf("step: |%f| x: |%d| y: |%d|\n", txtr.step, txtr.x, txtr.y);
	// // printf("%d\n", wall_x);
	//
	// double txtr_position = (wall_y - s->wdw.r_y / 2 + height / 2) * txtr.step;
	//printf("%lf\n", txtr_position);

	while (height-- > 0)
	{
		// txtr.y = (int)txtr_position & (txtr.img_data.height - 1);
		// index_texture = txtr.y * txtr.img_data.size_line + txtr.x;
		// index = wall_y * s->wdw.img_data.size_line + wall_x;
		// if (index > 0 && index < s->wdw.img_data.size_line * s->wdw.r_y)
		// 	put_pixel_img(s->wdw.img_data, txtr.img_data, index, index_texture);
		// txtr_position += txtr.step;
		// wall_y++;

		// if (wall_y < s->wdw.r_y)
		// {
		// 	pixel_put(s, wall_x, wall_y, color);
		// 	wall_y++;
		// }
	}
	draw_ceiling_floor(s, wall_x, wall_y, 0);
}
