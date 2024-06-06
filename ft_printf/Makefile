NAME = libftprintf.a
SRC =  ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putptr.c \
	   ft_putnbr.c \
	   ft_putunsigned.c \
	   ft_puthex.c \

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
