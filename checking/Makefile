NAME = check.a
LIBFT_A =	../libft/libft.a
GNL_A = ../gnl/gnl.a
MLX_A = ../minilibx_opengl/libmlx.a

FLAGS_MLX = -framework OpenGL -framework Appkit

DIR_LIB = ../libft
DIR_GNL = ../gnl
DIR_MLX = ../minilibx_opengl

SRCS = checking_map.c \
		checking_identifier.c \
		checking_identifier_utils.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(OBJS)
	@make -C $(DIR_GNL)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	# @make -C $(DIR_MLX)
	ar rc $(NAME) $(OBJS)
	# gcc -Wall -Wextra -Werror $(FLAGS_MLX)  $(NAME) $(GNL_A) $(LIBFT_A) $(MLX_A)
	gcc -Wall -Wextra -Werror $(NAME) $(GNL_A) $(LIBFT_A)
	@echo ------------------------------------------------------
	./a.out ../maps/1.cub | cat -e

%.o: %.c
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -rf *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
