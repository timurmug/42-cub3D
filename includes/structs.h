/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:37 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/15 15:05:44 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_sets
{
	void		*mlx;
	void		*wdw;
	int			r_x;
	int			r_y;
	void		*noth_texture;
	void		*south_texture;
	void		*west_texture;
	void		*east_texture;
	void		*sprite_texture;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceilling_r;
	int			ceilling_g;
	int			ceilling_b;
	char		**map;
	float		plr_x;
	float		plr_y;
	float		plr_d;
}				t_sets;

#endif
