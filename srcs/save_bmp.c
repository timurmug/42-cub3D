/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:34:33 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 14:42:09 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_headers(char *bfh, char *bih, int width, int height)
{
	int	file_size;

	file_size = 54 + 4 * width * height;
	bfh[0] = (unsigned char)('B');
	bfh[1] = (unsigned char)('M');
	bfh[2] = (unsigned char)(file_size);
	bfh[3] = (unsigned char)(file_size >> 8);
	bfh[4] = (unsigned char)(file_size >> 16);
	bfh[5] = (unsigned char)(file_size >> 24);
	bfh[10] = (unsigned char)(54);
	bih[0] = (unsigned char)(40);
	bih[4] = (unsigned char)(width);
	bih[5] = (unsigned char)(width >> 8);
	bih[6] = (unsigned char)(width >> 16);
	bih[7] = (unsigned char)(width >> 24);
	bih[8] = (unsigned char)(-height);
	bih[9] = (unsigned char)(-height >> 8);
	bih[10] = (unsigned char)(-height >> 16);
	bih[11] = (unsigned char)(-height >> 24);
	bih[12] = (unsigned char)(1);
	bih[14] = (unsigned char)(32);
}

void	save_bmp(t_sets *s, int i)
{
	char	bfh[14];
	char	bih[40];
	int		len;
	int		fd;

	if ((fd = open("Cub3D.bmp", O_RDWR | O_CREAT, 0755)) < 0)
	{
		ft_putendl_fd(FILE_OPEN_ERR, 1);
		return ;
	}
	ft_bzero(bfh, 14);
	ft_bzero(bih, 40);
	set_headers(bfh, bih, s->wdw.r_x, s->wdw.r_y);
	write(fd, bfh, 14);
	write(fd, bih, 40);
	i = 0;
	len = s->wdw.img_data.bpp / 8 * s->wdw.r_x;
	while (i < s->wdw.r_y)
	{
		write(fd, s->wdw.img_data.addr + i * s->wdw.img_data.size_line, len);
		i++;
	}
	if (close(fd < 0))
		ft_putendl_fd(FILE_CLOSE_ERROR, 1);
}
