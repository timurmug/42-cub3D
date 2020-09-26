/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:46:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 13:19:10 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

int				get_data(t_list **lines_list, t_sets *sets, \
	char **map, int count);
void			get_sprites(t_sets *sets);
void			save_bmp(t_sets *s, int i);
int				save_floor_color(char *s1, char *s2, char *s3, t_sets *sets);
int				save_ceilling_color(char *s1, char *s2, char *s3, t_sets *sets);
t_sets			sets_default(void);
#endif
