/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_identifier_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:52:00 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/09 08:06:26 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_r(char **s, t_sets *sets)
{
	int j;

	j = 0;
	if (ft_strstrlen(s) != 3)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	while (s[1][j])
		if (!ft_isdigit(s[1][j++]))
		{
			ft_putendl_fd(PARAM_TYPE_ERR, 1);
			return (-50);
		}
	j = 0;
	while (s[2][j])
		if (!ft_isdigit(s[2][j++]))
		{
			ft_putendl_fd(PARAM_TYPE_ERR, 1);
			return (-50);
		}
	sets->r_x = ft_atoi(s[1]);
	sets->r_y = ft_atoi(s[2]);
	return (1);
}

int	check_no(char **s, t_sets *sets)
{
	// int		width;
	// int		height;

	if (ft_strstrlen(s) != 2)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	(void)sets;
	// sets->noth_texture = mlx_xpm_file_to_image(sets->mlx, s[1], &width, &height);
	// if (!(sets->noth_texture))
	// {
	// 	ft_putendl_fd(TEXTURE_ERR, 1);
	// 	return (-50);
	// }
	return (1);
}

int	check_so(char **s, t_sets *sets)
{
	// int		width;
	// int		height;

	if (ft_strstrlen(s) != 2)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	(void)sets;
	// sets->south_texture = mlx_xpm_file_to_image(sets->mlx,	s[1], &width, &height);
	// if (!(sets->south_texture))
	// {
	// 	ft_putendl_fd(TEXTURE_ERR, 1);
	// 	return (-50);
	// }
	return (1);
}

int	check_we(char **s, t_sets *sets)
{
	// int		width;
	// int		height;

	if (ft_strstrlen(s) != 2)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	(void)sets;
	// sets->west_texture = mlx_xpm_file_to_image(sets->mlx, s[1], &width, &height);
	// if (!(sets->west_texture))
	// {
	// 	ft_putendl_fd(TEXTURE_ERR, 1);
	// 	return (-50);
	// }
	return (1);
}

int	check_ea(char **s, t_sets *sets)
{
	// int		width;
	// int		height;

	if (ft_strstrlen(s) != 2)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	(void)sets;
	// sets->east_texture = mlx_xpm_file_to_image(sets->mlx, s[1], &width, &height);
	// if (!(sets->east_texture))
	// {
	// 	ft_putendl_fd(TEXTURE_ERR, 1);
	// 	return (-50);
	// }
	return (1);
}
