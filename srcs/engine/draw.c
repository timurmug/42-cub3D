/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:23:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/18 13:42:33 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pixel_put(t_sets *s, int x, int y, int color)
{
    char    *dst;

    dst = s->wdw.addr + (y * s->wdw.size_line + x * (s->wdw.bpp / 8));
    *(unsigned int*)dst = color;
}

void	draw_ceiling_floor(t_sets *s, int x, double wall_y, int isceil)
{
	double temp_y;

	if (isceil)
	{
		temp_y = 0;
		if (wall_y > 0)
			while (temp_y < wall_y)
				pixel_put(s, x, temp_y++, s->ceiling_col);
	}
	else if (wall_y <= s->wdw.r_y)
		while (wall_y <= s->wdw.r_y)
			pixel_put(s, x, wall_y++, s->floor_col);
}

void	draw_column(t_sets *s, double curr_xy[2], int wall_x)
{
	double	ray;
	double	height;
	double	wall_y;

	ray = sqrt(pow(s->plr_x - curr_xy[0], 2) + pow(s->plr_y - curr_xy[1], 2));
	// ray *= cos();
	height = CELL / ray * ((double)s->plr_x / 2 / tanf(FOV_HALF));
	wall_y = (s->wdw.r_y / 2 - height / 2);
	ft_putnbr_fd(wall_y, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(height, 1);
	ft_putendl_fd("", 1);
	// (void)wall_x;
	// draw_ceiling_floor(s, wall_x, wall_y, 1);
	if (height >= s->wdw.r_y)
		height = s->wdw.r_y;
	if (wall_y < 0)
		wall_y = 0;
	while (height > 0)
	{
		if (wall_y < s->wdw.r_y)
		{
			pixel_put(s, wall_x, wall_y, 0x999999);
			wall_y++;
		}
		height--;
	}
	// draw_ceiling_floor(s, wall_x, wall_y, 0);
}

int		get_new_image(t_sets *s)
{
	if (s->wdw.img)
		mlx_destroy_image(s->wdw.mlx, s->wdw.img);
	 s->wdw.img = NULL;
	if (!(s->wdw.img = mlx_new_image(s->wdw.mlx, \
		s->wdw.r_x, s->wdw.r_y + 1)))
	{
		ft_putendl_fd(SMTH_ERR, 1);
		return (0);
	}
	s->wdw.addr = mlx_get_data_addr(s->wdw.img, \
		&s->wdw.bpp, &s->wdw.size_line, &s->wdw.endian);
	return (1);
}

void	calc_map(t_sets *s)
{
	double	step_xy[2];
	double	curr_xy[2];
	double	start_end[2];
	int		wall_x;

	if (!(get_new_image(s)))
		return ;
	wall_x = s->wdw.r_x;
	// draw_2dmap(s);
	start_end[0] = s->plr_d - FOV_HALF;
	start_end[1] = s->plr_d + FOV_HALF;
	while (start_end[0] < start_end[1])
	{
		step_xy[0] = cos(start_end[0]);
		step_xy[1] = -sin(start_end[0]);
		curr_xy[0] = s->plr_x;
		curr_xy[1] = s->plr_y;
		while (s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] &&\
		s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '1' && \
		s->map[(int)curr_xy[1] / SCALE][(int)curr_xy[0] / SCALE] != '2')
		{
			// mlx_pixel_put(s->wdw.mlx, s->wdw.wdw, curr_xy[0], curr_xy[1], 0xC2171D);
			curr_xy[0] += step_xy[0];
			curr_xy[1] += step_xy[1];
		}
		draw_column(s, curr_xy, wall_x);
		wall_x--;
		start_end[0] += FOV / s->wdw.r_x;
	}
	mlx_put_image_to_window(s->wdw.mlx, s->wdw.wdw, s->wdw.img, 0, 0);

}

void	create_window(t_sets sets)
{
	if (!sets.wdw.mlx)
		return mlx_err();
	if (!(sets.wdw.wdw = mlx_new_window(sets.wdw.mlx, \
		sets.wdw.r_x, sets.wdw.r_y, "cub3d")))
		return mlx_err();
	calc_map(&sets);
	mlx_hook(sets.wdw.wdw, 2, 1L<<0, button_pressed, &sets);
	mlx_hook(sets.wdw.wdw, 17, 1L<<0, cross_pressed, &sets);
	mlx_loop(sets.wdw.mlx);
}
