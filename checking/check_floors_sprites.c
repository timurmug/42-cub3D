/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floors_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:49:03 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/14 11:14:50 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_f_s2(char **m, size_t i, size_t max_i, char fs)
{
	size_t	j;
	size_t	max_j;

	max_j = ft_strlen(m[i]) - 1;
	j = 0;
	while (m[i][j])
	{
		if (m[i][j] == fs)
		{
			if (j == 0 || j == max_j || i == 0 || i == max_i)
				return (0);
			else if (j >= ft_strlen(m[i - 1]) || j >= ft_strlen(m[i + 1]))
				return (0);
			else if (m[i - 1][j - 1] == ' ' || m[i - 1][j] == ' ' \
			|| m[i - 1][j + 1] == ' ' || m[i][j - 1] == ' ' \
			|| m[i][j + 1] == ' ' || m[i + 1][j - 1] == ' ' \
			|| m[i + 1][j] == ' ' || m[i + 1][j + 1] == ' ')
				return (0);
			else if (m[i + 1][0] == '\0' || m[i - 1][0] == '\n' \
			|| m[i + 1][0] == '\0' || m[i - 1][0] == '\0')
				return (0);
		}
		j++;
	}
	return (1);
}

int	check_f_s(char **m, char fs)
{
	size_t	i;
	size_t	max_i;

	i = 0;
	max_i = ft_strstrlen(m) - 1;
	while (m[i])
	{
		if (!(check_f_s2(m, i, max_i, fs)))
		{
			if (fs == '0')
				ft_putendl_fd(FLOOR_ERROR, 1);
			else
				ft_putendl_fd(SPRITE_ERROR, 1);
			return (0);
		}
		i++;
	}
	return (1);
}
