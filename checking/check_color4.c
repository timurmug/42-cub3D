/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:19:27 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/12 10:34:53 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color4_3(char **s, t_sets *sets, int is_floor)
{
	if (s[2][0] == ',' && s[3][0] == ',')
	{
		s[2][0] = '\0';
		s[3][0] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], &s[2][1], &s[3][1], sets));
		else
			return (save_ceilling_color(s[1], &s[2][1], &s[3][1], sets));
	}
	else
		return (color_error());
}

int	check_color4(char **s, t_sets *sets, int is_floor)
{
	int len1;
	int len2;

	len1 = ft_strlen(s[1]);
	len2 = ft_strlen(s[2]);
	if (s[1][len1 - 1] == ',' && s[2][len2 - 1] == ',')
	{
		s[1][len1 - 1] = '\0';
		s[2][len2 - 1] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], s[2], s[3], sets));
		else
			return (save_ceilling_color(s[1], s[2], s[3], sets));
	}
	else if (s[2][0] == ',' && s[2][len2 - 1] == ',')
	{
		s[2][len2 - 1] = '\0';
		s[2][0] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], &s[2][1], s[3], sets));
		else
			return (save_ceilling_color(s[1], &s[2][1], s[3], sets));
	}
	else
		return (check_color4_3(s, sets, is_floor));
}
