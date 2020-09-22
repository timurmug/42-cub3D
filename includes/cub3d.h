/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:12:49 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/22 15:14:39 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include "errors.h"
# include "structs.h"
# include "funcs.h"

# define LEFT_BUTTON 123
# define RIGHT_BUTTON 124
# define ESC_BUTTON 53
# define W_BUTTON 13
# define A_BUTTON 0
# define S_BUTTON 1
# define D_BUTTON 2

# define SCALE 64
# define CELL 64
# define FOV (M_PI / 3)
# define FOV_HALF (M_PI / 6)
# define MOV_SPEED 10

#endif
