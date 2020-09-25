/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:03:29 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 14:28:08 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		create_map(t_list **lines_list, int size, int is_save)
{
	char		**map;
	t_sets		sets;
	int			count;

	map = ft_calloc(size + 1, sizeof(char *));
	sets = sets_default();
	count = 0;
	if (!get_data(lines_list, &sets, map, count))
	{
		free(map);
		return ;
	}
	print_strstr(map); //удалить
	sets.map = map;
	sets.map_size_y = ft_strstrlen(sets.map);
	get_sprites(&sets);
	sets.plr_x = sets.plr_x * SCALE + SCALE / 2;
	sets.plr_y = sets.plr_y * SCALE + SCALE / 2;
	print_sets(sets); //удалить
	create_window(sets, is_save);
	free(map);
	free(sets.sprites);
}


int			main(int ac, char **av)
{
	int			fd;
	char		*line;
	char		is_save;
	t_list		*lines_list;

	if (ac == 2 || (ac == 3 && !ft_strcmp(av[2], "--save")))
	{
		if ((fd = check_file_format(av[1])) < 0)
			return (0);
		line = NULL;
		lines_list = NULL;
		while (get_next_line(fd, &line))
		{
			ft_lstadd_back(&lines_list, ft_lstnew(line));
		}
		close(fd);
		ft_lstadd_back(&lines_list, ft_lstnew(line));
		is_save = (ac == 3) ? 1 : 0;
		create_map(&lines_list, ft_lstsize(lines_list), is_save);
	}
	else if (ac == 3 && ft_strcmp(av[2], "--save"))
		ft_putendl_fd(SAVE_PARAM_ERROR, 1);
	ft_list_clear(&lines_list);
	return (0);
}
