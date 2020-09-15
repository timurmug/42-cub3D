/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:17:27 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/15 10:37:56 by qtamaril         ###   ########.fr       */
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

void		ft_sets_free(t_sets sets)
{
	(void)sets;
	// ft_free_strstr(sets.mlx);
}

void		create_map(t_list **lines_list, int size)
{
	char		**map;
	t_sets		sets;
	int			count;

	map = ft_calloc(size + 1, sizeof(char *));
	sets = set_sets_default();
	count = 0;
	if (!get_data(lines_list, &sets, map, count))
	{
		free(map);
		return ;
	}
	print_strstr(map);
	print_sets(sets);
	free(map);
	// ft_sets_free(sets);
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
