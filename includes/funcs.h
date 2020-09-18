/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:46:32 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/18 15:41:48 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

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
int				get_texture(char **s, t_sets *sets, void **texture);
int				parse_identifier(char **s, t_sets *sets);
int				ft_str_is_num(char *str);
void			player_xy(t_list *tmp, t_sets *sets);
int				check_player(t_list *tmp);
int				check_line_map(char *s);
int				check_map(t_sets *sets, t_list *map_list, char **map);

int				type_repeated_err(void);
int				color_error(void);
int				param_type_err(void);
void			mlx_err(void);
void			ft_free_strstr(char **splitted);
void			ft_list_clear(t_list **begin_list);
char			**ft_strstrdup(char **s);
size_t			ft_strstrlen(char **splitted);

int				cross_pressed(t_sets *sets);
int				button_pressed(int key, t_sets *sets);
void			draw_2dmap(t_sets *sets);
void			calc_map(t_sets *s);
void			create_window(t_sets sets);

int				get_data(t_list **lines_list, t_sets *sets, \
	char **map, int count);

int				save_floor_color(char *s1, char *s2, char *s3, t_sets *sets);
int				save_ceilling_color(char *s1, char *s2, char *s3, t_sets *sets);

void			create_window(t_sets sets);

// удалить
void			print_sets(t_sets sets);
void			print_strstr(char **strstr);
#endif
