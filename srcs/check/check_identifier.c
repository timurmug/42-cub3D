/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:04:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/17 14:39:49 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_str_is_num(char *str)
{
	int j;

	j = 0;
	while (str[j])
		if (!ft_isdigit(str[j++]))
		{
			ft_putendl_fd(PARAM_TYPE_ERR, 1);
			return (0);
		}
	return (1);
}

int	check_r(char **s, t_sets *sets)
{
	int	x;
	int y;
	int	temp_x;
	int temp_y;

	if (sets->wdw.r_x != -1)
		return (type_repeated_err());
	if (ft_strstrlen(s) != 3)
	{
		ft_putendl_fd(PARAMS_NUM_ERR, 1);
		return (-50);
	}
	if (!ft_str_is_num(s[1]) || !ft_str_is_num(s[2]))
		return (-50);
	temp_x = ft_atoi(s[1]);
	temp_y = ft_atoi(s[2]);
	if (temp_x <= 0 || temp_y <= 0)
		return (param_type_err());
	mlx_get_screen_size(sets->wdw.mlx, &x, &y);
	// mlx_get_screen_size(sets->mlx, &x, &y);
	(temp_x < x) ? x = temp_x : 1 - 1;
	(temp_y < y) ? y = temp_y : 1 - 1;
	sets->wdw.r_x = x;
	sets->wdw.r_y = y;
	//
	// sets->r_x = temp_x;
	// sets->r_y = temp_y;
	return (1);
}

int	parse_identifier(char **s, t_sets *sets)
{
	int res;

	if (!ft_strcmp(s[0], "R"))
		res = check_r(s, sets);
	else if (!ft_strcmp(s[0], "NO"))
		res = get_texture(s, sets, &(sets->noth_texture));
	else if (!ft_strcmp(s[0], "SO"))
		res = get_texture(s, sets, &(sets->south_texture));
	else if (!ft_strcmp(s[0], "WE"))
		res = get_texture(s, sets, &(sets->west_texture));
	else if (!ft_strcmp(s[0], "EA"))
		res = get_texture(s, sets, &(sets->east_texture));
	else if (!ft_strcmp(s[0], "S"))
		res = get_texture(s, sets, &(sets->sprite_texture));
	else if (!ft_strcmp(s[0], "F"))
		res = check_color(s, sets, 1);
	else if (!ft_strcmp(s[0], "C"))
		res = check_color(s, sets, 0);
	else
	{
		ft_putendl_fd(LINE_ERROR, 1);
		res = -50;
	}
	ft_free_strstr(s);
	return (res);
}
