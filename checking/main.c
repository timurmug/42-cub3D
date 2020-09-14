/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:17:27 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/14 12:44:39 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_sets		set_sets_default(void)
{
	t_sets sets;

	sets.mlx = NULL;
	// sets.mlx = mlx_init();
	sets.wdw = NULL;
	sets.r_x = -1;
	sets.r_y = -1;
	sets.noth_texture = NULL;
	sets.south_texture = NULL;
	sets.west_texture = NULL;
	sets.east_texture = NULL;
	sets.sprite_texture = NULL;
	sets.floor_r = -1;
	sets.floor_g = -1;
	sets.floor_b = -1;
	sets.ceilling_r = -1;
	sets.ceilling_g = -1;
	sets.ceilling_b = -1;
	sets.map = NULL;
	sets.player_x = -1;
	sets.player_y = -1;
	return (sets);
}

int			check_spaces_paramsline(char *str, int count, int size)
{
	if (size == 0 && str[0] == ' ')
	{
		ft_putendl_fd(EMPTY_LINE_WITH_SPACES, 1);
		return (0);
	}
	if (count < 8 && size != 0)
	{
		if (str[0] == ' ')
		{
			ft_putendl_fd(SPACES_BEGIN_LINE, 1);
			return (0);
		}
		else if (str[ft_strlen(str) - 1] == ' ')
		{
			ft_putendl_fd(SPACES_END_LINE, 1);
			return (0);
		}
	}
	return (1);
}

// int			get_data2(t_list *elem, char **map, t_sets)
// {
// 	if (count < 8 && !check_spaces_paramsline((char *)elem->content, count, size))
// 	{
// 		ft_free_strstr(splitted);
// 		return (0);
// 	}
// 	else if (count < 8 && size != 0)
// 	{
// 		count += parse_identifier(splitted, sets);
// 		ft_free_strstr(splitted);
// 		if (count < 0)
// 			return (0);
// 	}
// 	else if (count >= 8)
// 	{
// 		ft_free_strstr(splitted);
// 		return (parse_map(sets, elem, map));
// 	}
// 	else
// 		ft_free_strstr(splitted);
// 	return (1);
// }

int			get_data(t_list **lines_list, t_sets *sets, char **map)
{
	t_list			*elem;
	char			**splitted;
	int				count;
	int				size;

	elem = *lines_list;
	count = 0;
	while (elem)
	{
		if (!(splitted = ft_split(elem->content, ' ')))
		{
			ft_putendl_fd(SMTH_ERR, 1);
			return (0);
		}
		size = ft_strstrlen(splitted);
		// if (!(get_data2()))
		// 	return (0);
		if (count < 8 && !check_spaces_paramsline((char *)elem->content, count, size))
		{
			ft_free_strstr(splitted);
			return (0);
		}
		else if (count < 8 && size != 0)
		{
			count += parse_identifier(splitted, sets);
			ft_free_strstr(splitted);
			if (count < 0)
				return (0);
		}
		else if (count >= 8)
		{
			ft_free_strstr(splitted);
			return (check_map(sets, elem, map));
		}
		else
			ft_free_strstr(splitted);
		elem = elem->next;
	}
	return (1);
}

void		create_map(t_list **lines_list, int size)
{
	char		**map;
	t_sets		sets;

	map = ft_calloc(size + 1, sizeof(char *));
	sets = set_sets_default();
	(void)lines_list;
	(void)size;
	if (!get_data(lines_list, &sets, map))
	{
		free(map);
		return ;
	}
	print_strstr(map);
	print_sets(sets);
	free(map);
}

int			main(int ac, char **av)
{
	int			fd;
	char		*line;
	t_list		*lines_list;

	if (ac == 2)
	{
		if ((fd = check_file_format(av[1])) < 0)
			return (0);
		line = NULL;
		lines_list = NULL;
		while (get_next_line(fd, &line))
		{
			ft_lstadd_back(&lines_list, ft_lstnew(line));
		}
		ft_lstadd_back(&lines_list, ft_lstnew(line));
		create_map(&lines_list, ft_lstsize(lines_list));
	}
	ft_list_clear(&lines_list);
	// while(1)
	// {
	// 	int i = 0;
	// 	i++;
	// }
	return (0);
}
