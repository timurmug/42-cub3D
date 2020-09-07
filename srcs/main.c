/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:03:29 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/07 15:19:53 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_square(void *mlx, void *wdw, int x, int y, int col)
{
	int temp_y;
	int temp_x;

	temp_y = y;
	while (temp_y < y + 50)
	{
		temp_x = x;
		while (temp_x < x + 50)
			mlx_pixel_put(mlx, wdw, temp_x++, temp_y, col);
		temp_y++;
	}
}

void create_window(char **map)
{
	void *mlx;
	void *wdw;
	int x;
	int y;
	int i;
	int j;

	mlx = NULL;
	wdw = NULL;
	mlx = mlx_init();
	wdw = mlx_new_window(mlx, 1920, 1080, "cub3d");
	y = 0;
	i = 9;

	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j])
		{
			if (map[i][j++] == '1')
				draw_square(mlx, wdw, x, y, 0xFFFFFF);
			else if (map[i][j - 1] == 'N' || map[i][j - 1] == 'S' \
							|| map[i][j - 1] == 'E' || map[i][j - 1] == 'W')
				draw_square(mlx, wdw, x, y, 0xC2171D);
			x += 50;
		}
		i++;
		y += 50;
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

	create_window(map);
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
