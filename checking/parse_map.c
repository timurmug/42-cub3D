/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:09:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/13 18:11:04 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	flood_fill(char **map, int y, int x)
{
	int s[8];

	if (x < 0 || y < 0 ||
		y >= (int)ft_strstrlen(map) ||
		x >= (int)ft_strlen(map[y])  ||
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

int	check_sprites(char **map) // попробовать проверку как у пола примерно. должны быть соседи 0 или 1
{
	// int		i;
	// int		j;
	// char	**tmp_map;
	//
	//
	// i = 0;
	// while (map[i])
	// {
	// 	j = 0;
	// 	while (map[i][j])
	// 	{
	// 		if (map[i][j] == '2')
	// 		{
	// 			if (!(tmp_map = ft_strstrdup(map)))
	// 			{
	// 				ft_putendl_fd(SMTH_ERR, 1);
	// 				return (0);
	// 			}
	// 			ft_putnbr_fd(i, 1);
	// 			ft_putchar_fd(' ', 1);
	// 			ft_putnbr_fd(j, 1);
	// 			ft_putendl_fd("", 1);
	//
	// 			if (!flood_fill(tmp_map, i, j))
	// 			{
	// 				ft_putendl_fd(SPRITE_ERROR, 1);
	// 				ft_free_strstr(tmp_map);
	// 				ft_free_strstr(map);
	// 				return (0);
	// 			}
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	// return (1);
}

int	parse_map(t_sets *sets, t_list *map_list, char **map)
{
	t_list *tmp_list;
	int		i;
	// int		j;
	char	**tmp_map;

	i = 0;
	tmp_list = map_list;
	sets->map = map_list;
	if (!check_player(map_list))
		return (0);
	// tmp_map = ft_calloc(ft_lstsize(map_list) + 1, sizeof(char *));
	while (tmp_list)
	{
		if (!check_line_map(tmp_list->content))
		{
			// free_strstr(tmp_map);
			ft_free_strstr(map);
			return (0);
		}
		map[i] = tmp_list->content;
		// tmp_map[i] = ft_strdup(map[i]);
		i++;
		tmp_list = tmp_list->next;
	}
	if (!(tmp_map = ft_strstrdup(map)))
	{
		ft_putendl_fd(SMTH_ERR, 1);
		return (0);
	}
	if (!check_floors(tmp_map, map))
		return (0);
	player_xy(map_list, sets);
	if (!flood_fill(tmp_map, sets->player_y, sets->player_x))
	{
		ft_putendl_fd(MAP_NOT_CLOSED_ERROR, 1);
		ft_free_strstr(tmp_map);
		ft_free_strstr(map);
		return (0);
	}
	if (!(check_sprites(map)))
		return (0);
	print_strstr(tmp_map);
	ft_free_strstr(map);
	return (1);
}
