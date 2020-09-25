/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_engine.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:13:38 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/25 18:48:07 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_ENGINE_H
# define FUNCS_ENGINE_H

int				close_mlx(t_sets *sets);
int				button_pressed(int key, t_sets *sets);
void			draw_2dmap(t_sets *sets);
// void			draw_img(t_sets *s);
void			draw_img(t_sets *s, int is_save);
t_dist			distance_to_wall_h(t_sets *s, double angle);
t_dist			distance_to_wall_v(t_sets *s, double angle);
void			draw_column(t_sets *s, int wall_x, double ray);

int				check_transparency(t_img texture, int index);
double			get_dir_sprite(t_sprite sprite, t_sets *s, double pov);
void			calculate_offset(t_sprite *sprite, t_sets *s, double angle);
// void			calculate_offset(t_sprite *sprite, t_sets *s, double angle);

void			draw_sprites(t_sets *s, double *distances);
void			pixel_put(t_sets *s, int x, int y, int color);
void			put_pixel_img(t_img img, t_img texture,
		int index, int index_texture);
double			ft_correct_angle(double angle);
t_dist			get_dist_and_texture(t_sets *s, double angle);
// void			create_window(t_sets sets);
void			create_window(t_sets sets, int is_save);

#endif
