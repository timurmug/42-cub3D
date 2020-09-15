# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 16:27:09 by qtamaril          #+#    #+#              #
#    Updated: 2020/09/15 11:00:50 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CUB_A = cub.a
LIBFT_A =	libft/libft.a
GNL_A = gnl/gnl.a
MLX_LIB = libmlx.dylib
# MLX_LIB = libmlx.dylib

FLAGS_W = -Wall -Wextra -Werror
FLAGS_MLX = -framework OpenGL -framework Appkit

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

SRCS = srcs/main.c \
		srcs/get_data.c \
		srcs/print_sets.c \
		srcs/save_color.c
OBJS = $(SRCS:%.c=%.o)

# SRCS_NAME = check.c \
# 						draw.c \
# 						main.c
# SRCS = $(addprefix $(DIR_SRCS)/,$(SRCS_NAME))
# OBJS = $(addprefix $(DIR_OBJS)/,$(SRCS_NAME:.c=.o))

.PHONY: all clean fclean re valg norme

all: $(NAME)

# one:$(OBJS)
# 	@make -C $(DIR_GNL)
# 	@make -C $(DIR_LIB)
# 	@make bonus -C $(DIR_LIB)
# 	@ar rc $(NAME) $(OBJS)
# 	gcc $(FLAGS_W) $(GNL_A) $(LIBFT_A) $(NAME) && ./a.out maps/example.cub

# two: $(OBJS)
# 	@make -C $(DIR_GNL)
# 	@make -C $(DIR_LIB)
# 	@make bonus -C $(DIR_LIB)
# 	@make -C $(DIR_MLX)
# 	@ar rc $(NAME) $(OBJS)
# 	gcc $(FLAGS_W) $(FLAGS_MLX) $(GNL_A) $(LIBFT_A) $(MLX_LIB) $(NAME)
# 	./a.out maps/1.cub

$(NAME): $(OBJS_CHECK) $(OBJS_UTILS) $(OBJS)
	# @make -C $(DIR_GNL)
	# @make -C $(DIR_LIB)
	# @make bonus -C $(DIR_LIB)
	@make -C $(DIR_MLX)
	# @cp $(MLX_LIB) $(DIR_LIB)/$(MLX_LIB)
	# ar rc $(CUB_A) $(OBJS) $(OBJS_CHECK)  $(OBJS_UTILS)
	# @cp $(CUB_A) $(DIR_SRCS)/$(CUB_A)
	# gcc $(FLAGS_W) $(FLAGS_MLX) $(CUB_A) $(GNL_A) $(LIBFT_A) $(MLX_LIB) -o $(NAME)
	# @echo ------------------------------------------------------
	# # ./$(NAME) ../maps/1.cub
	# ./$(NAME) ../maps/1.cub | cat -e


	# $(OBJS) $(PRINTF_H)
	# @make -C $(DIR_LIB)
	# @cp $(LIBFT_A) ./$(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	gcc $(FLAGS_W) -Iincludes -o $@ -c $<

valg:
	valgrind --leak-check=full ./$(NAME) ../maps/1.cub

norme:
	@make fclean
	norminette ./$(DIR_GNL)/
	@echo
	norminette ./$(DIR_LIB)/
	@echo
	norminette ./$(DIR_SRCS)/
	@echo
	norminette includes/

valg:
	valgrind --leak-check=full ./a.out

%.o: %.c
	gcc -c -Wall -Wextra -Werror -Imlx -o $@ $<

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
