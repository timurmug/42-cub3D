/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:46:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/14 12:44:00 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

void			draw_square(t_sets sets, int x, int y, int col);
void			draw_2dmap(char **map, t_sets sets);
int				check_map();
int				parse_identifier(char **s, t_sets *sets);
size_t			ft_strstrlen(char **splitted);

int				check_file_format(char *filename);

int				get_texture(char **s, t_sets *sets, void **texture);
int				check_no(char **s, t_sets *sets);
int				check_so(char **s, t_sets *sets);
int				check_we(char **s, t_sets *sets);
int				check_ea(char **s, t_sets *sets);
int				check_s(char **s, t_sets *sets);

int				check_color(char **s, t_sets *sets, int is_floor);
int				check_color2(char **s, t_sets *sets, int is_floor);
int				check_color3(char **s, t_sets *sets, int is_floor);
int				check_color4(char **s, t_sets *sets, int is_floor);
int				check_color5(char **s, t_sets *sets, int is_floor);
int				check_color6(char **s, t_sets *sets, int is_floor);
int				save_floor_color(char *s1, char *s2, char *s3, t_sets *sets);
int				save_ceilling_color(char *s1, char *s2, char *s3, t_sets *sets);
int				comma_issingle(char *s);
int				check_num(char *str);

int				check_map(t_sets *sets, t_list *map_list, char **map);
int				check_floors(char **m, char **map);
int				check_f_s(char **m, char fs);
void			player_xy(t_list *tmp, t_sets *sets);
int				check_player(t_list *tmp);
int				check_line_map(char *s);

int				color_error(void);
int				type_repeated_err(void);
int				param_type_err(void);

int				ft_str_is_num(char *str);
void			ft_free_strstr(char **splitted);
size_t			ft_strstrlen(char **splitted);
char			**ft_strstrdup(char **s);
void			ft_list_clear(t_list **begin_list);

// удалить
void			print_sets(t_sets sets);
void			print_strstr(char **strstr);
#endif
