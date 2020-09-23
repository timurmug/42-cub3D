/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:10:06 by qtamaril          #+#    #+#             */
/*   Updated: 2020/09/23 13:10:48 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_UTILS_H
# define FUNCS_UTILS_H

int				type_repeated_err(void);
int				color_error(void);
int				param_type_err(void);
void			mlx_err(void);
void			ft_free_strstr(char **splitted);
void			ft_list_clear(t_list **begin_list);
char			**ft_strstrdup(char **s);
size_t			ft_strstrlen(char **splitted);

#endif
