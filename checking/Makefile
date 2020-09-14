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

SRCS = checking_map.c \
		checking_identifier.c \
		checking_identifier_utils.c \
		check_color.c \
		print_sets.c \
		check_file.c \
		check_color2.c \
		check_color3.c \
		check_color4.c \
		check_color5.c \
		check_color6.c \
		errors.c \
		parse_map.c \
		parse_map_utils.c \
		check_floors_sprites.c \
		ft_free_strstr.c \
		ft_strstrdup.c \
		ft_strstrlen.c \
		ft_list_clear.c \
		save_color.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(OBJS)
	@make -C $(DIR_GNL)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	# @make -C $(DIR_MLX)
	ar rc $(CUB_A) $(OBJS)
	# gcc -Wall -Wextra -Werror $(FLAGS_MLX) $(CUB_A) $(GNL_A) $(LIBFT_A) $(MLX_LIB) -o $(NAME)
	gcc -g -std=c99 -Wall -Wextra -Werror $(CUB_A) $(GNL_A) $(LIBFT_A) -o $(NAME)
	@echo ------------------------------------------------------
	# ./$(NAME) ../maps/1.cub
	./$(NAME) ../maps/1.cub | cat -e

valg:
	valgrind --leak-check=full ./$(NAME) ../maps/1.cub

%.o: %.c
	gcc -c -Wall -Wextra -Werror -Imlx -o $@ $<

clean:
	rm -rf *.o

fclean: clean
	$(RM) $(CUB_A)
	$(RM) $(NAME)

re: fclean all
