/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_floors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:49:03 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/13 17:31:46 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_floors2(char **m, size_t i, size_t max_i)
{
	size_t	j;
	size_t	max_j;

	max_j = ft_strlen(m[i]) - 1;
	j = 0;
	while (m[i][j])
	{
		if (m[i][j] == '0')
		{
			if (j == 0 || j == max_j || i == 0 || i == max_i)
				return (0);
			else if (m[i - 1][j - 1] == ' ' || m[i - 1][j] == ' '\
			|| m[i - 1][j + 1] == ' '|| m[i][j - 1] == ' ' \
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

int	check_floors(char **m, char **map)
{
	size_t	i;
	size_t	max_i;

	i = 0;
	max_i = ft_strstrlen(m) - 1;
	while (m[i])
	{
		if (!(check_floors2(m, i, max_i)))
		{
			ft_putendl_fd(FLOOR_ERROR, 1);
			ft_free_strstr(m);
			ft_free_strstr(map);
			return (0);
		}
		i++;
	}
	return (1);
}
