/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:18:31 by qtamaril          #+#    #+#             */
/*   Updated: 2020/06/01 15:52:55 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
size_t			ft_strlen(char *str);
char			*ft_strchr(char *s, int c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *s);
char			*ft_strjoin_new(char *s1, char *s2);

#endif
