NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

GNL_DIR = ./get_next_line
GNL = $(GNL_DIR)/get_next_line.a

MLX_DIR = ./MLX42
MLX = $(MLX_DIR)/build/libmlx42.a

SRC =	./src/so_long.c					\
		./src/parsing.c					\
		./src/utils/utils1.c			\
		./src/utils/flood_fill.c		\
		./src/work_mlx/work_mlx.c		\
		./src/plays/player.c			\

OBJS = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(MLX_DIR)/include

all: $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(NAME)

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

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(MLX):
	@echo "$(GREEN)Building MLX42...${CLR_RMV}"
	@mkdir -p $(MLX_DIR)/build
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX) -o $(NAME) -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
	@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
	rm -f $(OBJS)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	@if [ -d $(MLX_DIR)/build ]; then cmake --build $(MLX_DIR)/build --target clean; fi

fclean: clean
	rm -f $(NAME)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -rf $(MLX_DIR)/build

re: fclean all

.PHONY: all clean fclean re