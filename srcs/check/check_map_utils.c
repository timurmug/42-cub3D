/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:51:22 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/16 09:43:59 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	plr_dir(char c)
{
	if (c == 'N')
		return (M_PI / 2);
		// return (90);
	else if (c == 'S')
		return (3 * M_PI / 2);
		// return (270);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (M_PI);
		return (180);
	return (-400);
}

void	player_xy(t_list *tmp, t_sets *sets)
{
	char	*s;
	int		y;
	int		i;

	y = 0;
	while (tmp)
	{
		i = 0;
		s = tmp->content;
		while (s[i])
		{
			if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
			{
				sets->plr_x = i;
				sets->plr_y = y;
				sets->plr_d = plr_dir(s[i]);
				return ;
			}
			i++;
		}
		tmp = tmp->next;
		y++;
	}
}

int		check_player(t_list *tmp)
{
	int		count;
	int		i;
	int		y;
	char	*s;

	count = 0;
	y = 0;
	while (tmp)
	{
		i = 0;
		s = tmp->content;
		while (s[i++])
			if (s[i - 1] == 'N' || s[i - 1] == 'S' \
			|| s[i - 1] == 'E' || s[i - 1] == 'W')
				count++;
		tmp = tmp->next;
		y++;
	}
	if (count == 1)
		return (1);
	else
	{
		ft_putendl_fd(PLAYER_ERROR, 1);
		return (0);
	}
}

int		check_line_map(char *s)
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
