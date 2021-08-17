NAME =	philo

INCLUDE = philo.h

SRC =		main.c \
			valid_argv.c \
			controler.c \
			philo_live.c \
			source.c \
			time_func.c \

OBJ_NAME	= $(SRC:.c=.o)

CC			= gcc -Wall -Wextra -Werror
# -pthread

RM			= rm -f

$(NAME):	$(OBJ_NAME) $(INCLUDE)
			$(CC) -o $(NAME) $(OBJ_NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ_NAME) 

fclean:		clean
			$(RM) ${NAME} 

re:			fclean all