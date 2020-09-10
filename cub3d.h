/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:12:49 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/10 11:16:18 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

# define FILE_TYPE_ERR "Error\nType of file is not .cub"
# define FILE_OPEN_ERR "Error\nError with opening the file"
# define SPACES_BEGIN_LINE "Error\nSpaces at the beginning of the params line"
# define SPACES_END_LINE "Error\nSpaces in the end of the params line"
# define EMPTY_LINE_WITH_SPACES "Error\nEmpty line with spaces"
# define TEXTURE_ERR "Error\nWrong path to texture"
# define PARAMS_NUM_ERR "Error\nWrong number of params"
# define PARAM_TYPE_ERR "Error\nWrong type of parameter"

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
	void		*floor_color;
	void		*ceilling_color;
}				t_sets;

void			draw_square(t_sets sets, int x, int y, int col);
void			draw_2dmap(char **map, t_sets sets);
int				check_map();
int				check_identifier(char **s, t_sets *sets);
size_t			ft_strstrlen(char **splitted);
int				check_no(char **s, t_sets *sets);
int				check_so(char **s, t_sets *sets);
int				check_we(char **s, t_sets *sets);
int				check_ea(char **s, t_sets *sets);
int				check_s(char **s, t_sets *sets);

#endif
