/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:15:18 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/14 10:02:49 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_file_format(char *filename)
{
	char			**splitted;
	size_t			size;
	int				fd;

	if (!(splitted = ft_split(filename, '.')))
	{
		ft_putendl_fd(FILE_ERR, 1);
		return (-1);
	}
	size = ft_strstrlen(splitted);
	if (ft_strcmp(splitted[size - 1], "cub"))
	{
		ft_putendl_fd(FILE_TYPE_ERR, 1);
		return (-1);
	}
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl_fd(FILE_OPEN_ERR, 1);
		return (-1);
	}
	ft_free_strstr(splitted);
	return (fd);
}
