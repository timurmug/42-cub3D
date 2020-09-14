/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:13:49 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/14 11:49:41 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	save_floor_color(char *s1, char *s2, char *s3, t_sets *sets)
{
	int r1;
	int g1;
	int b1;

	if (!ft_str_is_num(s1) \
	|| !ft_str_is_num(s2) || !ft_str_is_num(s3))
		return (-50);
	r1 = ft_atoi(s1);
	g1 = ft_atoi(s2);
	b1 = ft_atoi(s3);
	if (r1 <= 255 && g1 <= 255 && b1 <= 255)
	{
		sets->floor_r = r1;
		sets->floor_g = g1;
		sets->floor_b = b1;
	}
	else
		return (color_error());
	return (1);
}

int	save_ceilling_color(char *s1, char *s2, char *s3, t_sets *sets)
{
	int r1;
	int g1;
	int b1;

	if (!ft_str_is_num(s1) \
	|| !ft_str_is_num(s2) || !ft_str_is_num(s3))
		return (-50);
	r1 = ft_atoi(s1);
	g1 = ft_atoi(s2);
	b1 = ft_atoi(s3);
	if (r1 <= 255 && g1 <= 255 && b1 <= 255)
	{
		sets->ceilling_r = r1;
		sets->ceilling_g = g1;
		sets->ceilling_b = b1;
	}
	else
		return (color_error());
	return (1);
}
