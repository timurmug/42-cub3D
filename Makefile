# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 16:27:09 by qtamaril          #+#    #+#              #
#    Updated: 2020/09/07 16:51:32 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT_A =	libft/libft.a
GNL_A = gnl/gnl.a
MLX_A = minilibx_opengl/libmlx.a

FLAGS_W = -Wall -Wextra -Werror
FLAGS_MLX = -framework OpenGL -framework Appkit

CUBE3D_H = cub3d.h

DIR_OBJS	= objs
DIR_SRCS = srcs
DIR_LIB = libft
DIR_GNL = gnl
DIR_MLX = minilibx_opengl

SRCS_NAME = main.c draw.c
SRCS = $(addprefix $(DIR_SRCS)/,$(SRCS_NAME))
OBJS = $(addprefix $(DIR_OBJS)/,$(SRCS_NAME:.c=.o))

BOLD = "\e[1m"
FRGROUND  = "\e[90m"
BCGROUND = "\e[103m"
RESET = "\e[0m"

.PHONY: all clean fclean re two

all: $(NAME)

# one:
# 	$(LIBS)
# 	gcc $(FLAGS_W) main.c $(GNL_A) $(LIBFT_A) && ./a.out maps/example.cub

two: $(OBJS)
	@make -C $(DIR_GNL)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	@make -C $(DIR_MLX)
	@ar rc $(NAME) $(OBJS)
	gcc $(FLAGS_W) $(FLAGS_MLX) $(GNL_A) $(LIBFT_A) $(MLX_A) $(NAME)
	./a.out maps/1.cub

$(NAME): $(OBJS) $(PRINTF_H)
	@make -C $(DIR_LIB)
	@cp $(LIBFT_A) ./$(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	gcc -Wall -Wextra -Werror -Iincludes -o $@ -c $<

norme:
	@make fclean
	norminette ./$(DIR_GNL)/
	@echo
	norminette ./$(DIR_LIB)/
	@echo
	norminette ./$(DIR_SRCS)/
	@echo
	norminette $(CUBE3D_H)

valg:
	valgrind --leak-check=full ./a.out

clean:
	rm -rf $(DIR_OBJS)
	@make -C $(DIR_GNL) clean
	@make -C $(DIR_LIB) clean
	@make -C $(DIR_MLX) clean
	@echo $(BOLD)$(FRGROUND)$(BCGROUND)cleaned o-files$(RESET)

fclean: clean
	rm -f $(NAME)
	@make -C $(DIR_GNL) fclean
	@make -C $(DIR_LIB) fclean
	@echo $(BOLD)$(FRGROUND)$(BCGROUND)cleaned all files$(RESET)

re: fclean all
