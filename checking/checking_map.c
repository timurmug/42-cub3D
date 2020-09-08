#include "../cub3d.h"

size_t		ft_strstrlen(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
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

void		create_map(t_list **lines_list, int size)
{
	char		**map;
	int			i;
	t_list		*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	tmp = *lines_list;
	remove_empty_lines(&tmp);
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