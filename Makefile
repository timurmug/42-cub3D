# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 16:27:09 by qtamaril          #+#    #+#              #
#    Updated: 2020/09/06 19:03:10 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT_A =	libft/libft.a
GNL_A = gnl/gnl.a

FLAGS_W = -Wall -Wextra -Werror
FLAGS_B = -D BUFFER_SIZE=32

LIBFT_H = libft/libft.h
GNL_H = gnl/get_next_line.h
CUBE3D_H = cub3d.h

DIR_OBJS	= objs
DIR_SRCS = srcs
DIR_LIB = libft
DIR_GNL = gnl

SRCS_NAME =
SRCS = $(addprefix $(DIR_SRCS)/,$(SRCS_NAME))
OBJS = $(addprefix $(DIR_OBJS)/,$(SRCS_NAME:.c=.o))

SRCS_GNL_NAME = get_next_line.c \
								get_next_line_utils.c
SRCS_GNL = $(addprefix $(DIR_GNL)/,$(SRCS_GNL_NAME))
OBJS_GNL = $(addprefix $(DIR_OBJS)/,$(SRCS_GNL_NAME:.c=.o))

BOLD = "\e[1m"
FRGROUND  = "\e[90m"
BCGROUND = "\e[103m"
RESET = "\e[0m"

.PHONY: all clean fclean re first

all: $(NAME)

first:
	# $(OBJS_GNL)
	# ar rc $(GNL_A) $(OBJS_GNL)
	# cp $(GNL_A) ./$(NAME)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	@cp $(LIBFT_A) ./$(NAME)
	gcc $(FLAGS_W) $(FLAGS_B) main.c gnl/get_next_line.c gnl/get_next_line_utils.c $(NAME)

$(NAME): $(OBJS) $(PRINTF_H)
	@make -C $(DIR_LIB)
	@cp $(LIBFT_A) ./$(NAME)


$(DIR_OBJS)/%.o: $(DIR_GNL)/%.c
	@mkdir -p objs
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 -Iincludes -o $@ -c $<

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
	rm -f $(GNL_A)
	@make -C $(DIR_LIB) fclean
	@echo $(BOLD)$(FRGROUND)$(BCGROUND)cleaned all files$(RESET)

re: fclean all
