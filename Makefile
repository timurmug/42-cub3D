# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 16:27:09 by qtamaril          #+#    #+#              #
#    Updated: 2020/09/06 11:09:10 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT_A =	libft/libft.a

LIBFT_H = libft/libft.h
GNL_H = gnl/get_next_line.h
CUBE3D_H = cub3d.h

DIR_OBJS	= objs
DIR_SRCS = srcs
DIR_LIB = libft

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
	gcc -Wall -Wextra -Werror main.c 

$(NAME): $(OBJS) $(PRINTF_H)
	@make -C $(DIR_LIB)
	@cp $(LIBFT_A) ./$(NAME)


$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(PRINTF_H)
	@mkdir -p objs
	gcc -Wall -Wextra -Werror -Iincludes -o $@ -c $<

norme:
	norminette ./includes/
	@echo
	norminette ./$(DIR_LIB)/
	@echo
	norminette ./$(DIR_SRCS)/

valg:
	valgrind --leak-check=full ./a.out

clean:
	rm -f */*.o
	rm -rf $(DIR_OBJS)
	@echo $(BOLD)$(FRGROUND)$(BCGROUND)cleaned o-files$(RESET)

fclean: clean
	rm -f $(NAME)
	@make -C $(DIR_LIB) fclean
	@echo $(BOLD)$(FRGROUND)$(BCGROUND)cleaned all files$(RESET)

re: fclean all
