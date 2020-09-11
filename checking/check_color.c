/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:31:09 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/11 21:10:12 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	color_error()
{
	ft_putendl_fd(COLOR_PARAM_ERR, 1);
	return (-50);
}

int	save_floor_color(char *s1, char *s2, char *s3, t_sets *sets)
{
	int r1;
	int g1;
	int b1;

	if (!ft_str_is_num(s1) \
	|| !ft_str_is_num(s2) || !ft_str_is_num(s3))
		return (-50);
	r1 = ft_atoi(s1);
	g1 = ft_atoi(s2);
	b1 = ft_atoi(s3);
	if (r1 <= 255 && g1 <= 255 && b1 <= 255)
	{
		sets->floor_r = r1;
		sets->floor_g = g1;
		sets->floor_b = b1;
		// ft_putnbr_fd(r1, 1);
		// ft_putnbr_fd(g1, 1);
		// ft_putnbr_fd(b1, 1);
	}
	else
	{
		ft_putendl_fd(COLOR_PARAM_ERR, 1);
		return (-50);
	}
	return (1);
}

int comma_issingle(char *s)
{
	int i;
	int i2;
	int find;

	i = 0;
	find = 0;
	while (s[i])
		if (s[i++] == ',')
		{
			find++;
			i2 = i - 1;
		}
	if (find == 1)
		return (i2);
	else
		return (0);
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
		int comma;

		if (ft_str_is_num(s[2])) //здесь ошибка
		{
			if (s[1][ft_strlen(s[1]) - 1] == ',')
			{
				s[1][ft_strlen(s[1]) - 1] = '\0';
				if ((comma = comma_issingle(s[1])))
				{
					s[1][comma] = '\0';
					return (save_floor_color(s[1], &s[1][comma + 1], s[2], sets));
				}
				else
					return (color_error());
			}
			else
				return (color_error());
		}
		else if (s[1][ft_strlen(s[1]) - 1] == ',')
		{
			s[1][ft_strlen(s[1]) - 1] = '\0';
			if ((comma = comma_issingle(s[2])))
			{
				// s[2][comma] = '\0';
				// ft_putendl_fd(s[1], 1);
				// ft_putendl_fd(s[2], 1);
				// ft_putendl_fd(&s[2][comma + 1], 1);
				// return (save_floor_color(s[1], s[2], &s[2][comma + 1], sets));
				return (1);
			}
			else
				return (color_error());
		}
		else
			return (color_error());
	}
	else if (size == 4)
	{
		int len1;
		int len2;

		len1 = ft_strlen(s[1]);
		len2 = ft_strlen(s[2]);
		if (s[1][len1 - 1] == ',' && s[2][len2 - 1] == ',')
		{
			s[1][len1 - 1] = '\0';
			s[2][len2 - 1] = '\0';
			return (save_floor_color(s[1], s[2], s[3], sets));
		}
		else
			return (color_error());
	}
	else if (size == 5)
	{
		if (!ft_strcmp(s[3], ","))
		{
			int len;

			len = ft_strlen(s[1]);
			if (s[1][len - 1] == ',')
			{
				s[1][len - 1] = '\0';
				return (save_floor_color(s[1], s[2], s[4], sets));
			}
			else
				return (color_error());
		}
		else if (!ft_strcmp(s[2], ","))
		{
			int len;

			len = ft_strlen(s[3]);
			if (s[3][len - 1] == ',')
			{
				s[3][len - 1] = '\0';
				return (save_floor_color(s[1], s[3], s[4], sets));
			}
			else
				return (color_error());
		}
		else
			return (color_error());
	}
	else if (size == 6)
	{
		if (!ft_strcmp(s[2], ",") && !ft_strcmp(s[4], ","))
			return (save_floor_color(s[1], s[3], s[5], sets));
		else
			return (color_error());
	}
	return (color_error());
}
