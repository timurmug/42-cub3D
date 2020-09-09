/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:04:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/09 09:00:51 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_identifier(char **s, t_sets *sets)
{
	if (!ft_strcmp(s[0], "R"))
		return (check_r(s, sets));
	else if (!ft_strcmp(s[0], "NO"))
		return (check_no(s, sets));
	else if (!ft_strcmp(s[0], "SO"))
		return (check_so(s, sets));
	else if (!ft_strcmp(s[0], "WE"))
		return (check_we(s, sets));
	else if (!ft_strcmp(s[0], "EA"))
		return (check_ea(s, sets));
	else if (!ft_strcmp(s[0], "S"))
		return (1);
	else if (!ft_strcmp(s[0], "F"))
		return (1);
	else if (!ft_strcmp(s[0], "C"))
		return (1);
	else
		return (-50);
}
