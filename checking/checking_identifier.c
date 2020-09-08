/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:04:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/08 16:53:44 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_identifier(char **s, t_sets *sets)
{
	if (!ft_strncmp(s[0], "R", 1))
		return (check_r(s, sets));
	else if (!ft_strncmp(s[0], "NO", 2))
		return (check_no(s, sets));
	else if (!ft_strncmp(s[0], "SO", 2))
		return (check_so(s, sets));
	else if (!ft_strncmp(s[0], "WE", 2))
		return (check_we(s, sets));
	else if (!ft_strncmp(s[0], "EA", 2))
		return (check_ea(s, sets));
	else if (!ft_strncmp(s[0], "S", 1))
		return (1);
	else if (!ft_strncmp(s[0], "F", 1))
		return (1);
	else if (!ft_strncmp(s[0], "C", 1))
		return (1);
	else
		return (-50);
}
