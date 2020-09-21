/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:03:29 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/21 09:22:21 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		create_map(t_list **lines_list, int size)
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
	print_strstr(map);
	print_sets(sets);
	sets.map = map;
	sets.plr_x = sets.plr_x * SCALE + SCALE / 2;
	sets.plr_y = sets.plr_y * SCALE + SCALE / 2;
	create_window(sets);
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
