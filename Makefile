NAME = pushswap.a

NAMELIBFT = libft/libft.a

LIBDIR = ./include/

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(LIBDIR)

SRC_C = src/op_one.c \
		src/op_two.c \
		src/op_three.c \
		src/op_index.c \
		src/op_create_lst.c \
		src/sort_one.c \
		src/sort_100_plus.c \
		src/sort_100_plus_aux.c \
		src/sort_100_plus_aux_1.c \
		src/sort_100_less.c \
		src/check_sort.c \
		src/input.c \

SRC_C_BONUS = src_bonus/checker.c

all: $(NAME)

$(NAME):
	make all -C ./libft
	$(CC) -g $(CFLAGS) $(SRC_C) src/push_swap.c $(NAMELIBFT) -o push_swap

bonus: $(NAME)
	make all -C ./libft
	$(CC) -g $(CFLAGS) $(SRC_C) $(SRC_C_BONUS) $(NAMELIBFT) -o checker

clean:
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	rm -rf push_swap
	rm -rf checker

re: fclean all
