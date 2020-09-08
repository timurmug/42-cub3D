#include "../cub3d.h"

size_t		ft_strstrlen(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

t_sets		set_sets_default(void)
{
	t_sets sets;

	sets.mlx = NULL;
	sets.mlx = mlx_init();
	sets.wdw = NULL;
	sets.r_x = -1;
	sets.r_y = -1;
	sets.noth_texture = NULL;
	sets.south_texture = NULL;
	sets.west_texture = NULL;
	sets.east_texture = NULL;
	sets.sprite_texture = NULL;
	sets.floor_color = NULL;
	sets.ceilling_color = NULL;
	return (sets);
}

void		remove_empty_lines(t_list **lines_list)
{
	t_list			*elem;
	t_list			*tmp;
	char			**splitted;

	elem = *lines_list;
	while (elem && elem->next)
	{
		splitted = ft_split(elem->next->content, ' ');
		if (ft_strstrlen(splitted) == 0)
		{
			tmp = elem->next;
			elem->next = elem->next->next;
			free(tmp);
		}
		else
			elem = elem->next;
	}
	elem = *lines_list;
	splitted = ft_split(elem->content, ' ');
	if (ft_strstrlen(splitted) == 0)
	{
		*lines_list = elem->next;
		free(elem);
	}
}

int			remove_whitespaces(t_list **lines_list, t_sets *sets)
{
	t_list			*elem;
	int				i;
	char			**splitted;
	int				count;

	elem = *lines_list;
	count = 0;
	while (elem)
	{
		if (((char *)elem->content)[0] == ' ' && count < 8)
			return (0);
		else if (count < 8)
		{
			splitted = ft_split(elem->content, ' ');
			count += check_identifier(splitted, sets);
			if (count < 0)
				return (0);
			i = 1;
			elem->content = splitted[0];
			while (splitted[i])
			{
				elem->content = ft_strjoin(elem->content, " ");
				elem->content = ft_strjoin(elem->content, splitted[i++]);
			}
		}
		elem = elem->next;
	}
	return (1);
}

void		create_map(t_list **lines_list, int size)
{
	char		**map;
	int			i;
	t_list		*tmp;
	t_sets		sets;

	map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	tmp = *lines_list;
	sets = set_sets_default();
	remove_empty_lines(&tmp);
	if (!remove_whitespaces(&tmp, &sets))
		return ;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while (map[++i])
		ft_putendl_fd(map[i], 1);
}

int			main(int ac, char **av)
{
	int			fd;
	char		*line;
	t_list		*lines_list;

	fd = open(av[1], O_RDONLY);
	line = NULL;
	lines_list = NULL;
	if (ac == 2)
	{
		while (get_next_line(fd, &line))
			ft_lstadd_back(&lines_list, ft_lstnew(line));
		ft_lstadd_back(&lines_list, ft_lstnew(line));
		create_map(&lines_list, ft_lstsize(lines_list));
	}
	return (0);
}
