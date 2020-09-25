/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:34:05 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 14:38:01 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		type_repeated_err(void)
{
	ft_putendl_fd(DOUBLE_TYPE_ERR, 1);
	return (-50);
}

int		color_error(void)
{
	ft_putendl_fd(COLOR_PARAM_ERR, 1);
	return (-50);
}

int		param_type_err(void)
{
	ft_putendl_fd(PARAM_TYPE_ERR, 1);
	return (-50);
}

void	mlx_err(void)
{
	ft_putendl_fd(SMTH_ERR, 1);
	return ;
}
