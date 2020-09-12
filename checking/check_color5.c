/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:38:47 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/12 10:53:16 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color5_12(char **s, t_sets *sets, int is_floor)
{
	int len;

	len = ft_strlen(s[1]);
	if (s[1][len - 1] == ',')
	{
		s[1][len - 1] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], s[2], s[4], sets));
		else
			return (save_ceilling_color(s[1], s[2], s[4], sets));
	}
	else if (s[2][0] == ',')
	{
		s[2][0] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], &s[2][1], s[4], sets));
		else
			return (save_ceilling_color(s[1], &s[2][1], s[4], sets));
	}
	else
		return (color_error());
}

int	check_color5_34(char **s, t_sets *sets, int is_floor)
{
	int len;

	len = ft_strlen(s[3]);
	if (s[3][len - 1] == ',')
	{
		s[3][len - 1] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], s[3], s[4], sets));
		else
			return (save_ceilling_color(s[1], s[3], s[4], sets));
	}
	else if (s[4][0] == ',')
	{
		s[4][0] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], s[3], &s[4][1], sets));
		else
			return (save_ceilling_color(s[1], s[3], &s[4][1], sets));
	}
	else
		return (color_error());
}

int	check_color5(char **s, t_sets *sets, int is_floor)
{
	if (!ft_strcmp(s[3], ","))
		return (check_color5_12(s, sets, is_floor));
	else if (!ft_strcmp(s[2], ","))
		return (check_color5_34(s, sets, is_floor));
	else
		return (color_error());
}
