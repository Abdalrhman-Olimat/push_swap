CC		= cc
CFLAGS	= -Wall -Werror -Wextra 
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= error_handel.c  ft_atoi.c  init_stack.c  \
		main.c  push.c rev_rotate.c \
		rotate.c  sort_big.c  sort_five.c  sort_three.c \
		split.c  stack_utile.c  swap.c \
		big_sort_2.c big_sort_3.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
