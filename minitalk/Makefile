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

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT) 

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER) $(LIBFT) $(PRINTF)

clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re