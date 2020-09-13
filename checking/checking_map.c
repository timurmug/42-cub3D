#include "../cub3d.h"

t_sets		set_sets_default(void)
{
	t_sets sets;

	// sets.mlx = NULL;
	sets.mlx = mlx_init();
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

// void		remove_empty_lines(t_list **lines_list)
// {
// 	t_list			*elem;
// 	t_list			*tmp;
// 	char			**splitted;
//
// 	elem = *lines_list;
// 	while (elem && elem->next)
// 	{
// 		splitted = ft_split(elem->next->content, ' ');
// 		if (ft_strstrlen(splitted) == 0)
// 		{
// 			tmp = elem->next;
// 			elem->next = elem->next->next;
// 			free(tmp);
// 		}
// 		else
// 			elem = elem->next;
// 	}
// 	elem = *lines_list;
// 	splitted = ft_split(elem->content, ' ');
// 	if (ft_strstrlen(splitted) == 0)
// 	{
// 		*lines_list = elem->next;
// 		free(elem);
// 	}
// }

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
		if (count < 8 && !check_spaces_paramsline((char *)elem->content, count, size))
			return (0);
		else if (count < 8 && size != 0)
		{
			count += parse_identifier(splitted, sets);
			if (count < 0)
				return (0);
		}
		else if (count >= 8)
			return (parse_map(sets, elem, map));
		elem = elem->next;
	}
	return (1);
}

void		create_map(t_list **lines_list, int size)
{
	char		**map;
	// int			i;
	// t_list		*tmp;
	t_sets		sets;

	map = ft_calloc(size + 1, sizeof(char *));
	// i = -1;
	// tmp = *lines_list;
	sets = set_sets_default();
	// remove_empty_lines(&tmp);
	if (!get_data(lines_list, &sets, map))
	{
		free(map);
		return ;
	}
	// while (tmp)
	// {
	// 	map[++i] = tmp->content;
	// 	tmp = tmp->next;
	// }
	// i = -1;
	// while (map[++i])
	// 	ft_putendl_fd(map[i], 1);
	print_sets(sets);
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
			ft_lstadd_back(&lines_list, ft_lstnew(line));
		ft_lstadd_back(&lines_list, ft_lstnew(line));
		create_map(&lines_list, ft_lstsize(lines_list));
	}
	// while(1)
	// {
	// 	int i = 0;
	// 	i++;
	// }
	return (0);
}
