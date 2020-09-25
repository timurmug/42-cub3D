/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:37 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 11:50:12 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_txtr
{
	t_img			img_data;
	double			step;
	int				x;
	int				y;
}					t_txtr;

typedef struct		s_sprite
{
	t_txtr			txtr;
	double			x;
	double			y;
	double			dist;
	int				h_offset;
	int				v_offset;
	int				height;
}					t_sprite;

typedef struct		s_wdw
{
	void			*mlx;
	void			*wdw;
	t_img			img_data;
	int				r_x;
	int				r_y;
}					t_wdw;

typedef struct		s_sets
{
	t_wdw			wdw;
	t_txtr			curr_txtr;
	t_txtr			n_txtr;
	t_txtr			s_txtr;
	t_txtr			w_txtr;
	t_txtr			e_txtr;
	t_txtr			sprt_txtr;
	int				count_sprts;
	t_sprite		*sprites;
	int				floor_col;
	int				ceiling_col;
	char			**map;
	int				map_size_y;
	double			plr_x;
	double			plr_y;
	double			plr_d;
}					t_sets;

typedef struct		s_coords_int
{
	int				x;
	int				y;
}					t_coords_int;

typedef struct		s_coords_double
{
	double			x;
	double			y;
}					t_coords_double;

typedef struct		s_view
{
	double			start;
	double			end;
}					t_view;

typedef struct		s_dist
{
	double			dist;
	double			x;
}					t_dist;

typedef struct		s_bitmap_file_header
{
	char			bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bitmap_file_header;

typedef struct		s_bitmap_image_header
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bitmap_image_header;


#endif
