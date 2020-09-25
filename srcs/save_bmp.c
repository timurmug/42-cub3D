/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:34:33 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 12:42:57 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_bitmap_file_header	file_header_init(int file_size)
{
	t_bitmap_file_header	bmp_file_header;

	bmp_file_header.bitmap_type[0] = 'B';
	bmp_file_header.bitmap_type[1] = 'M';
	bmp_file_header.file_size = file_size;
	bmp_file_header.reserved1 = 0;
	bmp_file_header.reserved2 = 0;
	bmp_file_header.offset_bits = 0;
	return (bmp_file_header);
}

t_bitmap_image_header	image_header_init(int width, int height, int file_size)
{
	t_bitmap_image_header bmp_image_header;

	bmp_image_header.size_header = sizeof(bmp_image_header);
	bmp_image_header.width = width;
	bmp_image_header.height = -height;
	bmp_image_header.planes = 1;
	bmp_image_header.bit_count = 32;
	bmp_image_header.compression = 0;
	bmp_image_header.image_size = file_size;
	// bmp_image_header.ppm_x = 96 * 39.375;
	// bmp_image_header.ppm_y = 96 * 39.375;
	bmp_image_header.ppm_x = 3780;
	bmp_image_header.ppm_y = 3780;
	bmp_image_header.clr_used = 0;
	bmp_image_header.clr_important = 0;
	return (bmp_image_header);
}

void	save_bmp(int width, int height, char *data)
{
	int						fd;
	t_bitmap_file_header	bmp_file_header;
	t_bitmap_image_header	bmp_image_header;
	int						image_size;
	int						file_size;

	image_size = width * height;
	file_size = 54 + 4 * image_size;
	bmp_file_header = file_header_init(file_size);
	bmp_image_header = image_header_init(width, height, file_size);
	// fd = open("Cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	fd = open("Cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND);
	// fd = open("Cub3D.bmp", O_WRONLY | O_RDONLY);
	write(fd, &bmp_file_header, 14);
	write(fd, &bmp_image_header, sizeof(bmp_image_header));
	write(fd, data, image_size * 4);
	close(fd);
}
