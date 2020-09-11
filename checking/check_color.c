/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:31:09 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/11 16:51:53 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	color_error()
{
	ft_putendl_fd(COLOR_PARAM_ERR, 1);
	return (-50);
}

int	save_color(char **s, t_sets *sets, int is_floor)
{
	int r1;
	int g1;
	int b1;

	if (!ft_str_is_num(s[1]) \
	|| !ft_str_is_num(s[3]) || !ft_str_is_num(s[5]))
		return (0);
	r1 = ft_atoi(s[1]);
	g1 = ft_atoi(s[3]);
	b1 = ft_atoi(s[5]);
	if (0 <= r1 && r1 <= 255 && 0 <= g1 && g1 <= 255 && 0 <= b1  && b1 <= 255)
	{
		(is_floor == 1) ? sets->floor_r = r1 : 1 - 1;
		(is_floor == 1) ? sets->floor_g = g1 : 1 - 1;
		(is_floor == 1) ? sets->floor_b = b1 : 1 - 1;
		// ft_putnbr_fd(r1, 1);
		// ft_putnbr_fd(g1, 1);
		// ft_putnbr_fd(b1, 1);
	}
	else
		return (0);
	return (1);
}

int	check_f(char **s, t_sets *sets)
{
	int	size;

	size = ft_strstrlen(s);
	if (size == 2)
	{

	}
	else if (size == 3)
	{

	}
	else if (size == 4)
	{

	}
	else if (size == 5)
	{
		if (!ft_strcmp(s[3], ","))
		{
			//проверка на то, что у s[1] запятая на конце
			int len;

			len = ft_strlen(s[1]);
			if (s[1][len - 1] == ',')
			{
				s[1][len - 1] = '\0';
				// if (!ft_str_is_num(s[1]))
				// 	return (-50);
				// r = ft_atoi(s[1]);
			}
			else
				return (color_error());
		}
		else if (!ft_strcmp(s[2], ","))
		{
			//проверка на то,  что у s[1] запятая на конце
		}
		else
			return (color_error());
	}
	else if (size == 6)
	{
		if (!ft_strcmp(s[2], ",") && !ft_strcmp(s[4], ","))
		{
			if (!save_color(s, sets, 1))
				return (color_error());
		}
		else
			return (color_error());
	}
	else
		return (color_error());
	return (1);
}
