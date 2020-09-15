NAME = cub3D

CUB_A = check.a
LIBFT_A =	../libft/libft.a
GNL_A = ../gnl/gnl.a
# MLX_LIB = ../minilibx_opengl/libmlx.a
MLX_LIB = libmlx.dylib

FLAGS_MLX = -Lmlx -lmlx -framework OpenGL -framework Appkit

DIR_LIB = ../libft
DIR_GNL = ../gnl
DIR_MLX = ../minilibx

SRCS_CHECK = check/color/check_color.c \
			check/color/check_color2.c \
			check/color/check_color3.c \
			check/color/check_color4.c \
			check/color/check_color5.c \
			check/color/check_color6.c \
			check/check_file.c \
			check/check_floors_sprites.c \
			check/check_identifier.c \
			check/check_identifier_utils.c \
			check/check_map.c \
			check/check_map_utils.c
OBJS_CHECK = $(SRCS_CHECK:%.c=%.o)

SRCS_UTILS = utils/errors.c \
						utils/ft_free_strstr.c \
						utils/ft_list_clear.c \
						utils/ft_strstrdup.c \
						utils/ft_strstrlen.c
OBJS_UTILS = $(SRCS_UTILS:%.c=%.o)

SRCS = main.c \
		get_data.c \
		print_sets.c \
		save_color.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(OBJS_CHECK) $(OBJS_UTILS) $(OBJS)
	@make -C $(DIR_GNL)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	# @make -C $(DIR_MLX)
	ar rc $(CUB_A) $(OBJS) $(OBJS_CHECK)  $(OBJS_UTILS)
	gcc -Wall -Wextra -Werror $(FLAGS_MLX) $(CUB_A) $(GNL_A) $(LIBFT_A) $(MLX_LIB) -o $(NAME)
	# gcc -g -std=c99 -Wall -Wextra -Werror $(CUB_A) $(GNL_A) $(LIBFT_A) -o $(NAME)
	@echo ------------------------------------------------------
	# ./$(NAME) ../maps/1.cub
	./$(NAME) ../maps/1.cub | cat -e

valg:
	valgrind --leak-check=full ./$(NAME) ../maps/1.cub

%.o: %.c
	gcc -c -Wall -Wextra -Werror -Imlx -o $@ $<

clean:
	rm -rf *.o
	rm -rf check/*.o
	rm -rf check/color/*.o
	rm -rf utils/*.o

fclean: clean
	$(RM) $(CUB_A)
	$(RM) $(NAME)

re: fclean all
