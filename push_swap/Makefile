NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
SRC = 	./src/push_swap.c				\
		./src/parsing.c					\
		./src/utils/utils1.c			\
		./src/utils/utils2.c			\
		./src/utils/utils_algorithm.c	\
		./src/utils/utils_bigorder.c	\
		./src/utils/utils_cost.c		\
		./src/algorithm/algorithm.c 	\
		./src/algorithm/printstack.c    \
		./src/algorithm/bubble.c    	\
		./src/algorithm/order_3.c		\
		./src/algorithm/bigorder.c		\
		./src/algorithm/costs.c			\
		./src/moves/swap.c				\
		./src/moves/push.c				\
		./src/moves/rotate.c			\
		./src/moves/reverse_rotate.c	\

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I./libft

all: $(LIBFT) $(PRINTF) $(NAME)

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(SRC) $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
	rm -f $(NAME)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re