/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:03:29 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/17 14:42:52 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_wdw		set_wdw_default(void)
{
	t_wdw win;

	win.mlx = mlx_init();
	win.wdw = NULL;
	win.img = NULL;
	win.addr = NULL;
	win.bpp = -1;
	win.size_line = -1;
	win.endian = -1;
	win.r_x = -1;
	win.r_y = -1;
	return (win);
}
t_sets		set_sets_default(void)
{
	t_sets sets;

	sets.wdw = set_wdw_default();
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
	sets.plr_x = -1;
	sets.plr_y = -1;
	sets.plr_d = -400;
	return (sets);
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
