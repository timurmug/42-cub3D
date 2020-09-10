/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:31:09 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/10 18:02:48 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	save_color(char **s, int (*)colors[3])
{
	int r1;
	int g1;
	int b1;

	if (!ft_str_is_num(s[1]) \
	|| !ft_str_is_num(s[3]) || !ft_str_is_num(s[5]))
		return (-50);
	r1 = ft_atoi(s[1]);
	g1 = ft_atoi(s[3]);
	b1 = ft_atoi(s[5]);
	if (0 <= r1 && r1 <= 255 && 0 <= g1 && g1 <= 255 && 0 <= b1  && b1 <= 255)
	{
		*(colors[0]) = r1;
		*(colors[1]) = g1;
		*(colors[2]) = b1;
	}
	else
	{
		ft_putendl_fd(COLOR_PARAM_ERR, 1);
		return (0);
	}

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
			{
				ft_putendl_fd(COLOR_PARAM_ERR, 1);
				return (-50);
			}
		}
		else if (!ft_strcmp(s[2], ","))
		{
			//проверка на то,  что у s[1] запятая на конце
		}
		else
		{
			ft_putendl_fd(COLOR_PARAM_ERR, 1);
			return (-50);
		}
	}
	else if (size == 6)
	{
		if (!ft_strcmp(s[2], ",") && !ft_strcmp(s[4], ",") && \
		!save_color(s, &(sets->floor_colors)))
				return (-50);
		else
		{
			ft_putendl_fd(COLOR_PARAM_ERR, 1);
			return (-50);
		}
	}
	else
	{
		ft_putendl_fd(PARAM_TYPE_ERR, 1);
		return (-50);
	}
	ft_putendl_fd("-----------", 1);
	ft_putnbr_fd(sets->floor_colors[0], 1);
	ft_putendl_fd("-----------", 1);
	ft_putnbr_fd(sets->floor_colors[1], 1);
	ft_putendl_fd("-----------", 1);
	ft_putnbr_fd(sets->floor_colors[2], 1);
	ft_putendl_fd("-----------", 1);
	// ft_putendl_fd("-----------", 1);
	// ft_putnbr_fd(sets->floor_r, 1);
	// ft_putendl_fd("-----------", 1);
	// ft_putnbr_fd(sets->floor_g, 1);
	// ft_putendl_fd("-----------", 1);
	// ft_putnbr_fd(sets->floor_b, 1);
	// ft_putendl_fd("-----------", 1);
	return (1);
}
