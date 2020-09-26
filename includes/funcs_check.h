/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:08:17 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/26 13:19:20 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_CHECK_H
# define FUNCS_CHECK_H

int				comma_issingle(char *s);
int				check_num(char *str);
int				check_color(char **s, t_sets *sets, int is_floor);
int				check_color2(char **s, t_sets *sets, int is_floor);
int				check_color3(char **s, t_sets *sets, int is_floor);
int				check_color4(char **s, t_sets *sets, int is_floor);
int				check_color5(char **s, t_sets *sets, int is_floor);
int				check_color6(char **s, t_sets *sets, int is_floor);
int				check_file_format(char *filename);
int				check_f_s(char **m, char fs);
int				get_texture(char **str, t_sets *s, t_txtr *txtr);
int				parse_identifier(char **s, t_sets *sets);
int				ft_str_is_num(char *str);
void			player_xy(t_list *tmp, t_sets *sets);
int				check_player(t_list *tmp);
int				check_line_map(char *s);
int				check_map(t_sets *sets, t_list *map_list, char **map);

#endif
