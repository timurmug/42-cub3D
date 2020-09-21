/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 09:20:38 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/21 11:26:41 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img		img_default(void)
{
	t_img	img;

	img.img = NULL;
	img.addr = NULL;
	img.bpp = -1;
	img.size_line = -1;
	img.endian = -1;
	img.width = -1;
	img.height = -1;
	return (img);
}

t_txtr		t_txtr_default(void)
{
	t_txtr	txtr;

	txtr.img_data = img_default();
	txtr.step = -1;
	txtr.x = -1;
	txtr.y = -1;
	return (txtr);
}

t_wdw		wdw_default(void)
{
	t_wdw	win;

	win.mlx = mlx_init();
	win.wdw = NULL;
	win.img_data = img_default();
	// win.addr = NULL;
	// win.bpp = -1;
	// win.size_line = -1;
	// win.endian = -1;
	win.r_x = -1;
	win.r_y = -1;
	return (win);
}

t_sets		sets_default(void)
{
	t_sets	sets;

	sets.wdw = wdw_default();
	sets.n_txtr = t_txtr_default();
	sets.s_txtr= t_txtr_default();
	sets.w_txtr= t_txtr_default();
	sets.e_txtr= t_txtr_default();
	sets.sprt_txtr = t_txtr_default();
	// sets.noth_texture = NULL;
	// sets.south_texture = NULL;
	// sets.west_texture = NULL;
	// sets.east_texture = NULL;
	// sets.sprite_texture = NULL;
	sets.floor_col = -1;
	sets.ceiling_col = -1;
	sets.map = NULL;
	sets.plr_x = -1;
	sets.plr_y = -1;
	sets.plr_d = -400;
	return (sets);
}
