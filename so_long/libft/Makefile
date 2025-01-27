#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := libft.a
CC        := clang
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      ft_atoi.c \
                          ft_bzero.c \
                          ft_calloc.c \
                          ft_isalnum.c \
                          ft_isalpha.c \
                          ft_isascii.c \
                          ft_isdigit.c \
                          ft_isprint.c \
                          ft_itoa.c \
                          ft_memchr.c \
                          ft_memcmp.c \
                          ft_memcpy.c \
                          ft_memmove.c \
                          ft_memset.c \
                          ft_putchar_fd.c \
                          ft_putendl_fd.c \
                          ft_putnbr_fd.c \
                          ft_putstr_fd.c \
                          ft_split.c \
                          ft_strchr.c \
                          ft_strdup.c \
                          ft_striteri.c \
                          ft_strjoin.c \
                          ft_strlcat.c \
                          ft_strlcpy.c \
                          ft_strlen.c \
                          ft_strmapi.c \
                          ft_strncmp.c \
                          ft_strnstr.c \
                          ft_strrchr.c \
                          ft_strtrim.c \
                          ft_substr.c \
                          ft_tolower.c \
                          ft_toupper.c \

BONUS_SRC = 			  ft_lstnew.c \
						  ft_lstadd_front.c \
						  ft_lstsize.c \
						  ft_lstlast.c \
						  ft_lstadd_back.c \
						  ft_lstdelone.c \
						  ft_lstclear.c \
						  ft_lstiter.c \
						  ft_lstmap.c \

OBJS        := $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			$(AR) rcs $(NAME) $(OBJS)
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		${BONUS_OBJS}
			$(AR) rcs $(NAME) $(BONUS_OBJS)

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re bonus