# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 16:27:09 by qtamaril          #+#    #+#              #
#    Updated: 2020/09/07 08:37:06 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT_A =	libft/libft.a
GNL_A = gnl/gnl.a

FLAGS_W = -Wall -Wextra -Werror

CUBE3D_H = cub3d.h

DIR_OBJS	= objs
DIR_SRCS = srcs
DIR_LIB = libft
DIR_GNL = gnl

SRCS_NAME =
SRCS = $(addprefix $(DIR_SRCS)/,$(SRCS_NAME))
OBJS = $(addprefix $(DIR_OBJS)/,$(SRCS_NAME:.c=.o))

BOLD = "\e[1m"
FRGROUND  = "\e[90m"
BCGROUND = "\e[103m"
RESET = "\e[0m"

.PHONY: all clean fclean re first

all: $(NAME)

first:
	@make -C $(DIR_GNL)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	gcc $(FLAGS_W) main.c $(LIBFT_A) $(GNL_A)

$(NAME): $(OBJS) $(PRINTF_H)
	@make -C $(DIR_LIB)
	@cp $(LIBFT_A) ./$(NAME)

norme:
	norminette ./$(DIR_GNL)/
	@echo
	norminette ./$(DIR_LIB)/
	@echo
	norminette ./$(DIR_SRCS)/

valg:
	valgrind --leak-check=full ./a.out

clean:
	rm -rf $(DIR_OBJS)
	@make -C $(DIR_GNL) clean
	@make -C $(DIR_LIB) clean
	@echo $(BOLD)$(FRGROUND)$(BCGROUND)cleaned o-files$(RESET)

fclean: clean
	rm -f $(NAME)
	@make -C $(DIR_GNL) fclean
	@make -C $(DIR_LIB) fclean
	@echo $(BOLD)$(FRGROUND)$(BCGROUND)cleaned all files$(RESET)

re: fclean all
