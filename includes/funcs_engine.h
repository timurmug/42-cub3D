/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_engine.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:13:38 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/23 15:52:07 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_ENGINE_H
# define FUNCS_ENGINE_H

int				cross_pressed(t_sets *sets);
int				button_pressed(int key, t_sets *sets);
void			draw_2dmap(t_sets *sets);
void			calc_map(t_sets *s);
t_dist			distance_to_wall_h(t_sets *s, double angle);
t_dist			distance_to_wall_v(t_sets *s, double angle);
void			draw_column(t_sets *s, int wall_x, double ray);
void			pixel_put(t_sets *s, int x, int y, int color);
void			put_pixel_img(t_img img, t_img texture,
		int index, int index_texture);
double			ft_correct_angle(double angle);
t_dist			get_dist_and_texture(t_sets *s, double angle);
void			create_window(t_sets sets);
int				save_floor_color(char *s1, char *s2, char *s3, t_sets *sets);
int				save_ceilling_color(char *s1, char *s2, char *s3, t_sets *sets);

void			create_window(t_sets sets);

#endif
