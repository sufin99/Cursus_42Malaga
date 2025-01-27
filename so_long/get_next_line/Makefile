NAME = get_next_line.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *_bonus.c)
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
	rm -f $(OBJ)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	rm -f $(NAME)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all clean fclean re