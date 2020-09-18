/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:52:00 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/18 08:35:38 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_texture(char **s, t_sets *sets, void **texture)
{
	int		w;
	int		h;

	if (*texture != NULL)
		return (type_repeated_err());
	if (ft_strstrlen(s) != 2)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	// (void)sets;
	if (!(*texture = mlx_xpm_file_to_image(sets->wdw.mlx, s[1], &w, &h)))
	{
		ft_putendl_fd(TEXTURE_ERR, 1);
		return (-50);
	}
	return (1);
}
