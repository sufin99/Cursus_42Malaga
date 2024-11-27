NAME_CLIENT = client
NAME_SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
SRC_CLIENT = client.c
SRC_SERVER = server.c

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I./libft

all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

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

$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME_CLIENT) ${CLR_RMV}..."
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)
	@echo "$(GREEN)$(NAME_CLIENT) created[0m ✔️"

$(NAME_SERVER): $(SRC_SERVER) $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME_SERVER) ${CLR_RMV}..."
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)
	@echo "$(GREEN)$(NAME_SERVER) created[0m ✔️"

clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@ echo "$(RED)Deleting $(CYAN)$(NAME_CLIENT) $(NAME_SERVER) $(CLR_RMV)objs ✔️"
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@ echo "$(RED)Deleting $(CYAN)$(NAME_CLIENT) $(NAME_SERVER) $(CLR_RMV)binary ✔️"
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re