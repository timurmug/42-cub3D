/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:09:53 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/14 11:11:51 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color6(char **s, t_sets *sets, int is_floor)
{
	if (!ft_strcmp(s[2], ",") && !ft_strcmp(s[4], ","))
	{
		if (is_floor)
			return (save_floor_color(s[1], s[3], s[5], sets));
		else
			return (save_ceilling_color(s[1], s[3], s[5], sets));
	}
	else
		return (color_error());
}
