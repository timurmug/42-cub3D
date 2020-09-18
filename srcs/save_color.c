/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:13:49 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/18 10:41:12 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	save_floor_color(char *s1, char *s2, char *s3, t_sets *sets)
{
	int r;
	int g;
	int b;

	if (!ft_str_is_num(s1) \
	|| !ft_str_is_num(s2) || !ft_str_is_num(s3))
		return (-50);
	r = ft_atoi(s1);
	g = ft_atoi(s2);
	b = ft_atoi(s3);
	if (r <= 255 && g <= 255 && b <= 255)
		sets->floor_col = ((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff);
	else
		return (color_error());
	return (1);
}

int	save_ceilling_color(char *s1, char *s2, char *s3, t_sets *sets)
{
	int r;
	int g;
	int b;

	if (!ft_str_is_num(s1) \
	|| !ft_str_is_num(s2) || !ft_str_is_num(s3))
		return (-50);
	r = ft_atoi(s1);
	g = ft_atoi(s2);
	b = ft_atoi(s3);
	if (r <= 255 && g <= 255 && b <= 255)
		sets->ceiling_col = ((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff);
	else
		return (color_error());
	return (1);
}
