NAME = check.a
LIBFT_A =	../libft/libft.a
GNL_A = ../gnl/gnl.a

DIR_LIB = ../libft
DIR_GNL = ../gnl

SRCS = checking_map.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(DIR_GNL)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	ar rc $(NAME) $(OBJS)
	gcc -Wall -Wextra -Werror $(NAME) $(GNL_A) $(LIBFT_A)
	@echo ------------------------------------------------------
	./a.out ../maps/1.cub

%.o: %.c
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -rf *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
