/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:46:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 11:55:43 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

int				get_data(t_list **lines_list, t_sets *sets, \
	char **map, int count);
void			get_sprites(t_sets *sets);
void			save_bmp(int width, int height, char *data);
int				save_floor_color(char *s1, char *s2, char *s3, t_sets *sets);
int				save_ceilling_color(char *s1, char *s2, char *s3, t_sets *sets);
t_sets			sets_default(void);

// удалить
void			print_sets(t_sets sets);
void			print_strstr(char **strstr);
#endif
