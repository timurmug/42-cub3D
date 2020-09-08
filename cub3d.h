/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:12:49 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/08 08:26:43 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx_opengl/mlx.h"
# include <fcntl.h>

# define R_X 5120
# define R_Y 2880

typedef struct	s_sets
{
	void		*mlx;
	void		*wdw;
}				t_sets;

void			draw_square(t_sets sets, int x, int y, int col);
void			draw_2dmap(char **map, t_sets sets);
int				check_map();

#endif
