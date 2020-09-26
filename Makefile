# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 16:27:09 by qtamaril          #+#    #+#              #
#    Updated: 2020/09/26 13:23:07 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CUB_A = srcs/cub.a
LIB_A =	libft/libft.a
GNL_A = gnl/gnl.a
MLX_LIB = minilibx/libmlx.dylib

INCLUDES = includes/cub3d.h \
			includes/errors.h \
			includes/funcs.h \
			includes/structs.h

FLAGS_W = -Wall -Wextra -Werror
FLAGS_MLX = -Lmlx -lmlx -framework OpenGL -framework Appkit

DIR_SRCS = srcs
DIR_LIB = libft
DIR_GNL = gnl
DIR_MLX = minilibx

SRCS_CHECK = srcs/check/color/check_color.c \
			srcs/check/color/check_color2.c \
			srcs/check/color/check_color3.c \
			srcs/check/color/check_color4.c \
			srcs/check/color/check_color5.c \
			srcs/check/color/check_color6.c \
			srcs/check/check_file.c \
			srcs/check/check_floors_sprites.c \
			srcs/check/check_identifier.c \
			srcs/check/check_identifier_utils.c \
			srcs/check/check_map.c \
			srcs/check/check_map_utils.c
OBJS_CHECK = $(SRCS_CHECK:%.c=%.o)

SRCS_UTILS = srcs/utils/errors.c \
			srcs/utils/ft_free_strstr.c \
			srcs/utils/ft_list_clear.c \
			srcs/utils/ft_strstrdup.c \
			srcs/utils/ft_strstrlen.c
OBJS_UTILS = $(SRCS_UTILS:%.c=%.o)

SRCS = srcs/engine/buttons.c \
		srcs/engine/distance_to_wall_h.c \
		srcs/engine/distance_to_wall_v.c \
		srcs/engine/draw_2dmap.c \
		srcs/engine/draw_columns.c \
		srcs/engine/draw_sprites_utils.c \
		srcs/engine/draw_sprites.c \
		srcs/engine/draw_utils.c \
		srcs/engine/draw.c \
		srcs/get_data.c \
		srcs/get_sprites.c \
		srcs/main.c \
		srcs/save_bmp.c \
		srcs/set_default.c \
		srcs/save_color.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re valg norme run save bonus

all: $(NAME)

$(NAME): $(INCLUDES) $(OBJS_CHECK) $(OBJS_UTILS) $(OBJS)
	@make -C $(DIR_GNL)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	@make -C $(DIR_MLX)
	cp $(MLX_LIB) libmlx.dylib
	ar rc $(CUB_A) $(OBJS) $(OBJS_CHECK)  $(OBJS_UTILS)
	gcc $(FLAGS_W) $(FLAGS_MLX) $(CUB_A) $(GNL_A) $(LIB_A) $(MLX_LIB) -o $(NAME)
	@echo ------------------------------------------------------
	# ./$(NAME) ../maps/1.cub
	./$(NAME) maps/1.cub | cat -e

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	gcc $(FLAGS_W) -Iincludes -o $@ -c $<

bonus: all

run:
	./$(NAME) maps/1.cub | cat -e

valg:
	valgrind --leak-check=full ./$(NAME) ../maps/1.cub

save:
	./$(NAME) maps/1.cub --save

norme:
	@make fclean
	# @echo
	# norminette includes/
	# @echo
	# norminette ./$(DIR_GNL)/
	# @echo
	# norminette ./$(DIR_LIB)/
	@echo
	norminette ./$(DIR_SRCS)/

%.o: %.c
	gcc -c $(FLAGS_W) -Imlx -o $@ $<

clean:
	rm -rf $(OBJS_CHECK) $(OBJS_UTILS) $(OBJS)
	@make -C $(DIR_GNL) clean
	@make -C $(DIR_LIB) clean
	@make -C $(DIR_MLX) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(CUB_A)
	@make -C $(DIR_GNL) fclean
	@make -C $(DIR_LIB) fclean
	rm -f libmlx.dylib

re: fclean all
