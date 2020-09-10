/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:04:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/10 17:31:43 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_str_is_num(char *str)
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
	int	temp_x;
	int y;
	int temp_y;

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

int	parse_identifier(char **s, t_sets *sets)
{
	if (!ft_strcmp(s[0], "R"))
		return (check_r(s, sets));
	else if (!ft_strcmp(s[0], "NO"))
		return (get_texture(s, sets, &(sets->noth_texture)));
		// return (check_no(s, sets));
	else if (!ft_strcmp(s[0], "SO"))
		return (get_texture(s, sets, &(sets->south_texture)));
		// return (check_so(s, sets));
	else if (!ft_strcmp(s[0], "WE"))
		return (get_texture(s, sets, &(sets->west_texture)));
		// return (check_we(s, sets));
	else if (!ft_strcmp(s[0], "EA"))
		return (get_texture(s, sets, &(sets->east_texture)));
		// return (check_ea(s, sets));
	else if (!ft_strcmp(s[0], "S"))
		return (get_texture(s, sets, &(sets->sprite_texture)));
		// return (check_s(s, sets));
	else if (!ft_strcmp(s[0], "F"))
		return (check_f(s, sets));
	else if (!ft_strcmp(s[0], "C"))
		return (1);
	else
		return (-50);
}
