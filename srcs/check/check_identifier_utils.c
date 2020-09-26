/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:52:00 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 14:07:34 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_texture(char **str, t_sets *s, t_txtr *txtr)
{
	if (txtr->img_data.img != NULL)
		return (type_repeated_err());
	if (ft_strstrlen(str) != 2)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	if (!(txtr->img_data.img = mlx_xpm_file_to_image(s->wdw.mlx, str[1], \
		&txtr->img_data.width, &txtr->img_data.height)))
	{
		ft_putendl_fd(TEXTURE_ERR, 1);
		return (-50);
	}
	txtr->img_data.addr = mlx_get_data_addr(txtr->img_data.img, \
		&txtr->img_data.bpp, &txtr->img_data.size_line, &txtr->img_data.endian);
	return (1);
}
