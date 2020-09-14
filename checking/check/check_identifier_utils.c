/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_identifier_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:52:00 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/14 12:37:05 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_texture(char **s, t_sets *sets, void **texture)
{
	// int		w;
	// int		h;

	if (*texture != NULL)
		return (type_repeated_err());
	if (ft_strstrlen(s) != 2)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	(void)sets;
	// *texture = mlx_xpm_file_to_image(sets->mlx, s[1], &w, &h);
	// if (!(*texture))
	// {
	// 	ft_putendl_fd(TEXTURE_ERR, 1);
	// 	return (-50);
	// }
	// ft_putendl_fd("-----------", 1);
	// ft_putendl_fd(sets->noth_texture, 1);
	// ft_putendl_fd("-----------", 1);
	// ft_putendl_fd("-----------", 1);
	// ft_putendl_fd(mlx_get_data_addr(*texture, &img->bpp, &img->line_length,
	// 															&img->endian);, 1);
	// ft_putendl_fd("-----------", 1);
	// (void)texture;
	return (1);
}
