/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/23 15:52:20 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_new_image(t_sets *s)
{
	if (s->wdw.img_data.img)
		mlx_destroy_image(s->wdw.mlx, s->wdw.img_data.img);
	s->wdw.img_data.img = NULL;
	if (!(s->wdw.img_data.img = mlx_new_image(s->wdw.mlx, \
		s->wdw.r_x, s->wdw.r_y + 1)))
	{
		ft_putendl_fd(SMTH_ERR, 1);
		return (0);
	}
	s->wdw.img_data.addr = mlx_get_data_addr(s->wdw.img_data.img, \
		&s->wdw.img_data.bpp, &s->wdw.img_data.size_line, &s->wdw.img_data.endian);
	return (1);
}

void	calc_map(t_sets *s)
{
	t_view	view;
	int		wall_x;
	double	curr_angle;
	t_dist	dist;

	if (!(get_new_image(s)))
		return ;
	wall_x = 0;
	view.start = s->plr_d + FOV_HALF;
	view.end = s->plr_d - FOV_HALF;
	while (view.start > view.end)
	{
		curr_angle = ft_correct_angle(view.start);
		dist = get_dist_and_texture(s, curr_angle);
		s->curr_txtr.x = (int)(SCALE * dist.x);
		draw_column(s, wall_x, dist.dist);
		wall_x++;
		view.start -= (FOV / s->wdw.r_x);
	}
	mlx_put_image_to_window(s->wdw.mlx, s->wdw.wdw, s->wdw.img_data.img, 0, 0);
}

void	create_window(t_sets sets)
{
	if (!sets.wdw.mlx)
		return mlx_err();
	if (!(sets.wdw.wdw = mlx_new_window(sets.wdw.mlx, \
		sets.wdw.r_x, sets.wdw.r_y, "cub3d")))
		return mlx_err();
	calc_map(&sets);
	mlx_hook(sets.wdw.wdw, 2, 1L<<0, button_pressed, &sets);
	mlx_hook(sets.wdw.wdw, 17, 1L<<0, cross_pressed, &sets);
	mlx_loop(sets.wdw.mlx);
}
