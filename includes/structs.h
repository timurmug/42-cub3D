/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:37 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/18 11:12:33 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_wdw
{
	void		*mlx;
	void		*wdw;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	void		*img_temp;
	char		*addr_temp;
	int			bpp_temp;
	int			size_line_temp;
	int			endian_temp;
	int			r_x;
	int			r_y;
}				t_wdw;

typedef struct	s_sets
{
	t_wdw		wdw;
	void		*noth_texture;
	void		*south_texture;
	void		*west_texture;
	void		*east_texture;
	void		*sprite_texture;
	int			floor_col;
	int			ceiling_col;
	char		**map;
	double		plr_x;
	double		plr_y;
	double		plr_d;
}				t_sets;

#endif
