/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:09:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/12 13:46:06 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_line_map(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '0' && s[i] != '1' && s[i] != '2' \
		&& s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W')
		{
			ft_putendl_fd(LINE_ERROR, 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_map(t_sets *sets, t_list *map_list)
{
	(void)sets;
	t_list *tmp;

	tmp = map_list;
	sets->map = map_list;
	while (tmp)
	{
		if (!check_line_map(tmp->content))
			return (0);
		ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
	return (1);
}
