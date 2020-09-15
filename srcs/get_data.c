/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:35:28 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/15 10:36:35 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_space_pline(char *str, int count, int size)
{
	if (size == 0 && str[0] == ' ')
	{
		ft_putendl_fd(EMPTY_LINE_WITH_SPACES, 1);
		return (0);
	}
	if (count < 8 && size != 0)
	{
		if (str[0] == ' ')
		{
			ft_putendl_fd(SPACES_BEGIN_LINE, 1);
			return (0);
		}
		else if (str[ft_strlen(str) - 1] == ' ')
		{
			ft_putendl_fd(SPACES_END_LINE, 1);
			return (0);
		}
	}
	return (1);
}

int	get_data1(void)
{
	ft_putendl_fd(SMTH_ERR, 1);
	return (0);
}

int	get_data2(char **splitted)
{
	ft_free_strstr(splitted);
	return (0);
}

int	get_data3(char **splitted, t_sets *sets, t_list *elem, char **map)
{
	ft_free_strstr(splitted);
	return (check_map(sets, elem, map));
}

int	get_data(t_list **lines_list, t_sets *sets, char **map, int count)
{
	t_list			*elem;
	char			**splitted;
	int				size;

	elem = *lines_list;
	while (elem)
	{
		if (!(splitted = ft_split(elem->content, ' ')))
			return (get_data1());
		size = ft_strstrlen(splitted);
		if (count < 8 && !check_space_pline((char *)elem->content, count, size))
			return (get_data2(splitted));
		else if (count < 8 && size != 0)
		{
			if ((count += parse_identifier(splitted, sets)) < 0)
				return (0);
		}
		else if (count >= 8)
			return (get_data3(splitted, sets, elem, map));
		else
			ft_free_strstr(splitted);
		elem = elem->next;
	}
	return (1);
}
