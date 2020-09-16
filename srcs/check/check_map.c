/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:09:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/16 09:27:31 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	flood_fill(char **map, int y, int x)
{
	int s[8];

	if (x < 0 || y < 0 ||
		y >= (int)ft_strstrlen(map) ||
		x >= (int)ft_strlen(map[y]) ||
		map[y][x] == ' ' || \
		map[y][x] == 0 || map[y] == 0)
		return (0);
	else if (map[y][x] == '1' || map[y][x] == '.')
		return (1);
	map[y][x] = '.';
	s[0] = flood_fill(map, y, x + 1);
	s[1] = flood_fill(map, y, x - 1);
	s[2] = flood_fill(map, y + 1, x);
	s[3] = flood_fill(map, y - 1, x);
	s[4] = flood_fill(map, y + 1, x + 1);
	s[5] = flood_fill(map, y + 1, x - 1);
	s[6] = flood_fill(map, y + 1, x + 1);
	s[7] = flood_fill(map, y - 1, x + 1);
	return (s[0] && s[1] && s[2] && s[3] && s[4] && s[5] && s[6] && s[7]);
}

int	check_sprites2(char **m, size_t i, size_t max_i)
{
	size_t	j;
	size_t	max_j;

	max_j = ft_strlen(m[i]) - 1;
	j = 0;
	while (m[i][j])
	{
		if (m[i][j] == '2')
		{
			if (j == 0 || j == max_j || i == 0 || i == max_i)
				return (0);
			else if (m[i - 1][j - 1] == ' ' || m[i - 1][j] == ' '\
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

int	check_sprites(char **m, char **map)
{
	size_t	i;
	size_t	max_i;

	i = 0;
	max_i = ft_strstrlen(m) - 1;
	while (m[i])
	{
		if (!(check_sprites2(m, i, max_i)))
		{
			ft_putendl_fd(SPRITE_ERROR, 1);
			ft_free_strstr(m);
			ft_free_strstr(map);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map2(t_sets *sets, t_list *map_list, char **map)
{
	char		**tmp_map;

	if (!(check_f_s(map, '0')) || !(check_f_s(map, '2')))
		return (0);
	if (!(tmp_map = ft_strstrdup(map)))
	{
		ft_putendl_fd(SMTH_ERR, 1);
		return (0);
	}
	player_xy(map_list, sets);
	if (!flood_fill(tmp_map, (int)sets->plr_y, (int)sets->plr_x))
	{
		ft_putendl_fd(MAP_NOT_CLOSED_ERROR, 1);
		ft_free_strstr(tmp_map);
		return (0);
	}
	ft_free_strstr(tmp_map);
	return (1);
}

int	check_map(t_sets *sets, t_list *map_list, char **map)
{
	t_list		*tmp_list;
	int			i;

	i = 0;
	tmp_list = map_list;
	// sets->map = map_list;
	if (!check_player(map_list))
		return (0);
	while (tmp_list)
	{
		if (!check_line_map(tmp_list->content))
		{
			return (0);
		}
		map[i] = tmp_list->content;
		i++;
		tmp_list = tmp_list->next;
	}
	return (check_map2(sets, map_list, map));
}
