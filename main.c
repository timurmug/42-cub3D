/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:03:29 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/07 13:31:53 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void create_window()
{
	void *mlx;
	void *wdw;
	int x;
	int y;

	mlx = NULL;
	wdw = NULL;
	y = 100;
	mlx = mlx_init();
	wdw = mlx_new_window(mlx, 640, 480, "cub3d");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
			mlx_pixel_put(mlx, wdw, x, y, 0xFFFFFF); 
	}
	mlx_loop(mlx);
}

void create_map(t_list **lines_list, int size)
{
	char **map;
	int i;
	t_list *tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	tmp = *lines_list;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = 10;
	while (map[++i])
		ft_putendl_fd(map[i], 1);

	create_window();
}

int	main(	int ac, char **av)
{
	int fd;
	char *line;
	t_list *lines_list;

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
