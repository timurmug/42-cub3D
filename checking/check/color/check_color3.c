/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:04:48 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/14 12:34:44 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	check_color3_1(char **s, t_sets *sets, int is_floor)
{
	int c;

	if (s[1][ft_strlen(s[1]) - 1] == ',')
	{
		s[1][ft_strlen(s[1]) - 1] = '\0';
		if ((c = comma_issingle(s[1])))
		{
			s[1][c] = '\0';
			if (is_floor)
				return (save_floor_color(s[1], &s[1][c + 1], s[2], sets));
			else
				return (save_ceilling_color(s[1], &s[1][c + 1], s[2], sets));
		}
		else
			return (color_error());
	}
	else
		return (color_error());
}

int	check_color3_2(char **s, t_sets *sets, int is_floor)
{
	int c;

	s[1][ft_strlen(s[1]) - 1] = '\0';
	if ((c = comma_issingle(s[2])))
	{
		s[2][c] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], s[2], &s[2][c + 1], sets));
		else
			return (save_ceilling_color(s[1], s[2], &s[2][c + 1], sets));
	}
	else
		return (color_error());
}

int	check_color3_3(char **s, t_sets *sets, int is_floor)
{
	int c;

	s[2][0] = '\0';
	if ((c = comma_issingle(s[1])))
	{
		s[1][c] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], &s[1][c + 1], &s[2][1], sets));
		else
			return (save_ceilling_color(s[1], &s[1][c + 1], &s[2][1], sets));
	}
	else
		return (color_error());
}

int	check_color3_4(char **s, t_sets *sets, int is_floor)
{
	int c;

	s[2][0] = '\0';
	if ((c = comma_issingle(&s[2][1])))
	{
		s[2][c + 1] = '\0';
		if (is_floor)
			return (save_floor_color(s[1], &s[2][1], &s[2][c + 2], sets));
		else
			return (save_ceilling_color(s[1], &s[2][1], &s[2][c + 2], sets));
	}
	else
		return (color_error());
}

int	check_color3(char **s, t_sets *sets, int is_floor)
{
	if (check_num(s[2]))
		return (check_color3_1(s, sets, is_floor));
	else if (s[1][ft_strlen(s[1]) - 1] == ',')
		return (check_color3_2(s, sets, is_floor));
	else if (!check_num(s[1]) && s[2][0] == ',')
		return (check_color3_3(s, sets, is_floor));
	else if (check_num(s[1]) && s[2][0] == ',')
		return (check_color3_4(s, sets, is_floor));
	return (color_error());
}
