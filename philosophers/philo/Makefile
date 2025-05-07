NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = 	./src/main.c          \
		./src/parseo.c        \
		./src/philo.c         \
		./src/init_philos.c   \
		./src/monitor.c       \
		./src/routine.c       \
		./src/print_error.c   \
		./src/utils.c         \
		

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m


$(NAME): $(SRC)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
	rm -f $(NAME)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	rm -f $(NAME)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all clean fclean re