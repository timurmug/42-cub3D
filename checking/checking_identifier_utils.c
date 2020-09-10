/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_identifier_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:52:00 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/10 17:14:40 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_texture(char **s, t_sets *sets, void **texture)
{
	int		w;
	int		h;

	if (ft_strstrlen(s) != 2)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	// (void)sets;
	*texture = mlx_xpm_file_to_image(sets->mlx, s[1], &w, &h);
	if (!(*texture))
	{
		ft_putendl_fd(TEXTURE_ERR, 1);
		return (-50);
	}
	// ft_putendl_fd("-----------", 1);
	// ft_putendl_fd(sets->noth_texture, 1);
	// ft_putendl_fd("-----------", 1);
	return (1);
}

// int	check_no(char **s, t_sets *sets)
// {
// 	int		w;
// 	int		h;
//
// 	if (ft_strstrlen(s) != 2)
// 	{
// 		ft_putendl_fd(PARAMS_NUM_ERR, 1);
// 		return (-50);
// 	}
// 	// (void)sets;
// 	sets->noth_texture = mlx_xpm_file_to_image(sets->mlx, s[1], &w, &h);
// 	if (!(sets->noth_texture))
// 	{
// 		ft_putendl_fd(TEXTURE_ERR, 1);
// 		return (-50);
// 	}
//
// 	ft_putendl_fd("-----------", 1);
// 	ft_putendl_fd((char *)sets->noth_texture, 1);
// 	ft_putendl_fd("-----------", 1);
// 	return (1);
// }
//
// int	check_so(char **s, t_sets *sets)
// {
// 	int		w;
// 	int		h;
//
// 	if (ft_strstrlen(s) != 2)
// 	{
// 		ft_putendl_fd(PARAMS_NUM_ERR, 1);
// 		return (-50);
// 	}
// 	// (void)sets;
// 	sets->south_texture = mlx_xpm_file_to_image(sets->mlx, s[1], &w, &h);
// 	if (!(sets->south_texture))
// 	{
// 		ft_putendl_fd(TEXTURE_ERR, 1);
// 		return (-50);
// 	}
// 	return (1);
// }
//
// int	check_we(char **s, t_sets *sets)
// {
// 	int		w;
// 	int		h;
//
// 	if (ft_strstrlen(s) != 2)
// 	{
// 		ft_putendl_fd(PARAMS_NUM_ERR, 1);
// 		return (-50);
// 	}
// 	// (void)sets;
// 	sets->west_texture = mlx_xpm_file_to_image(sets->mlx, s[1], &w, &h);
// 	if (!(sets->west_texture))
// 	{
// 		ft_putendl_fd(TEXTURE_ERR, 1);
// 		return (-50);
// 	}
// 	return (1);
// }
//
// int	check_ea(char **s, t_sets *sets)
// {
// 	int		w;
// 	int		h;
//
// 	if (ft_strstrlen(s) != 2)
// 	{
// 		ft_putendl_fd(PARAMS_NUM_ERR, 1);
// 		return (-50);
// 	}
// 	// (void)sets;
// 	sets->east_texture = mlx_xpm_file_to_image(sets->mlx, s[1], &w, &h);
// 	if (!(sets->east_texture))
// 	{
// 		ft_putendl_fd(TEXTURE_ERR, 1);
// 		return (-50);
// 	}
// 	return (1);
// }
//
// int	check_s(char **s, t_sets *sets)
// {
// 	int		w;
// 	int		h;
//
// 	if (ft_strstrlen(s) != 2)
// 	{
// 		ft_putendl_fd(PARAMS_NUM_ERR, 1);
// 		return (-50);
// 	}
// 	// (void)sets;
// 	sets->sprite_texture = mlx_xpm_file_to_image(sets->mlx, s[1], &w, &h);
// 	if (!(sets->sprite_texture))
// 	{
// 		ft_putendl_fd(TEXTURE_ERR, 1);
// 		return (-50);
// 	}
// 	return (1);
// }
