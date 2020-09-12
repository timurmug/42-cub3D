/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:54:08 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/12 11:31:45 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	commas_correct(char *s)
{
	int i;
	int i1;
	int i2;
	int find;
	int last;

	i = 0;
	i1 = -1;
	i2 = -1;
	find = 0;
	last = ft_strlen(s) - 1;
	while (s[i])
		if (s[i++] == ',')
		{
			find++;
			if (i1 == -1)
				i1 = i - 1;
			else
				i2 = i - 1;
		}
	if (find == 2 && i1 != -1 && i1 != 0 && i2 != -1 && i2 != last)
		return (1);
	else
		return (0);
}

int	check_color2(char **s, t_sets *sets, int is_floor)
{
	char	**split;
	int		size;

	if (!(commas_correct(s[1])))
		return (color_error());
	if (!(split = ft_split(s[1], ',')))
	{
		ft_putendl_fd(SMTH_ERR, 1);
		return (-50);
	}
	if ((size = ft_strstrlen(split)) != 3)
		return (color_error());
	if (is_floor)
		return (save_floor_color(split[0], split[1], split[2], sets));
	else
		return (save_ceilling_color(split[0], split[1], split[2], sets));
}
