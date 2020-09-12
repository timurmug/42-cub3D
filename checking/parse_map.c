/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:09:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/12 19:17:24 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void player_xy(t_list *tmp, t_sets *sets)
{
	char	*s;
	int		y;
	int		i;

	y = 0;
	while (tmp)
	{
		i = 0;
		s = tmp->content;
		while (s[i])
		{
			if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
			{
				sets->player_x = i;
				sets->player_y = y;
				return ;
			}
			i++;
		}
		tmp = tmp->next;
		y++;
	}
}

int	check_player(t_list *tmp)
{
	int		count;
	int		i;
	int		y;
	char	*s;

	count = 0;
	y = 0;
	while (tmp)
	{
		i = 0;
		s = tmp->content;
		while (s[i++])
			if (s[i - 1] == 'N' || s[i - 1] == 'S' \
			|| s[i - 1] == 'E' || s[i - 1] == 'W')
				count++;
		tmp = tmp->next;
		y++;
	}
	if (count == 1)
		return (1);
	else
	{
		ft_putendl_fd(PLAYER_ERROR, 1);
		return (0);
	}
}

int	check_line_map(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '0' && s[i] != '1' && s[i] != '2' \
		&& s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W')
		{
			ft_putendl_fd(LINE_ERROR, 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	flood_fill(char **tmp, int y, int x)
{
	int s[8];

	if (x < 0 || y < 0 ||
		y >= (int)ft_strstrlen(tmp) ||
		x >= (int)ft_strlen(tmp[y])  ||
		tmp[y][x] == ' ' || \
		tmp[y][x] == 0 || tmp[y] == 0)
		return (0);
	else if (tmp[y][x] == '1' || tmp[y][x] == '.')
		return (1);
	tmp[y][x] = '.';
	s[0] = flood_fill(tmp, y, x + 1);
	s[1] = flood_fill(tmp, y, x - 1);
	s[2] = flood_fill(tmp, y + 1, x);
	s[3] = flood_fill(tmp, y - 1, x);
	s[4] = flood_fill(tmp, y + 1, x + 1);
	s[5] = flood_fill(tmp, y + 1, x - 1);
	s[6] = flood_fill(tmp, y + 1, x + 1);
	s[7] = flood_fill(tmp, y - 1, x + 1);
	return (s[0] && s[1] && s[2] && s[3] && s[4] && s[5] && s[6] && s[7]);
}


int	parse_map(t_sets *sets, t_list *map_list, char **map)
{
	t_list *tmp;
	int		i;
	// int		j;
	char	**tmp_map;

	i = 0;
	tmp = map_list;
	sets->map = map_list;
	if (!check_player(map_list))
		return (0);
	tmp_map = ft_calloc(ft_lstsize(map_list) + 1, sizeof(char *));
	while (tmp)
	{
		if (!check_line_map(tmp->content))
		{
			free(tmp_map);
			return (0);
		}
		// map[i++] = tmp->content;
		// ft_memset(map[i++], '.', ft_strlen(tmp->content));
		map[i] = tmp->content;
		tmp_map[i] = ft_strdup(tmp->content);
		// j = 0;
		// while (tmp_map[i][j++])
		// 	if (tmp_map[i][j - 1] != '1' && tmp_map[i][j - 1] != ' ')
		// 		tmp_map[i][j - 1] = '.';
		// ft_putendl_fd(tmp_map[i], 1);
		// ft_putendl_fd(map[i], 1);
		i++;
		tmp = tmp->next;
	}
	player_xy(map_list, sets);
	if (!flood_fill(tmp_map, sets->player_y, sets->player_x))
	{
		ft_putendl_fd("Map is not closed", 1);
		free_strstr(tmp_map);
		return (0);
	}
	// tmp_map[sets->player_y][sets->player_x] = '*';
	// tmp_map[26][0] = '*';
	// ft_putnbr_fd(sets->player_x, 1);
	// ft_putendl_fd("", 1);
	// ft_putnbr_fd(sets->player_y, 1);
	// ft_putendl_fd("", 1);
	i = 0;
	while (tmp_map[i])
	{
		ft_putendl_fd(tmp_map[i], 1);
		i++;
	}
	free_strstr(tmp_map);
	return (1);
}
