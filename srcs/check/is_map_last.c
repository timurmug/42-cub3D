/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:51:36 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 17:12:01 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map_last(char **map)
{
	char	**splitted;
	int		size;
	int		len;

	size = ft_strstrlen(map) - 2;
	while (map[size])
	{
		if (!(splitted = ft_split(map[size], ' ')))
		{
			ft_putendl_fd(SMTH_ERR, 1);
			return (0);
		}
		len = ft_strstrlen(splitted);
		ft_free_strstr(splitted);
		if (!len)
		{
			ft_putendl_fd(MAP_NOT_LAST_PARAM, 1);
			return (0);
		}
		else
			return (1);
		size--;
	}
	return (1);
}
