/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:04:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/10 11:16:11 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_r2(char **s, t_sets *sets)
{
	int	x;
	int	temp_x;
	int y;
	int temp_y;

	temp_x = ft_atoi(s[1]);
	temp_y = ft_atoi(s[2]);
	if (temp_x <= 0 || temp_y <= 0)
	{
		ft_putendl_fd(PARAM_TYPE_ERR, 1);
		return (-50);
	}
	mlx_get_screen_size(sets->mlx, &x, &y);
	(temp_x < x) ? x = temp_x : 1 - 1;
	(temp_y < y) ? y = temp_y : 1 - 1;
	sets->r_x = x;
	sets->r_y = y;
	return (1);
}

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
	return (check_r2(s, sets));
}

int	check_identifier(char **s, t_sets *sets)
{
	if (!ft_strcmp(s[0], "R"))
		return (check_r(s, sets));
	else if (!ft_strcmp(s[0], "NO"))
		return (check_no(s, sets));
	else if (!ft_strcmp(s[0], "SO"))
		return (check_so(s, sets));
	else if (!ft_strcmp(s[0], "WE"))
		return (check_we(s, sets));
	else if (!ft_strcmp(s[0], "EA"))
		return (check_ea(s, sets));
	else if (!ft_strcmp(s[0], "S"))
		return (check_s(s, sets));
	else if (!ft_strcmp(s[0], "F"))
		return (1);
	else if (!ft_strcmp(s[0], "C"))
		return (1);
	else
		return (-50);
}
