# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 18:25:55 by eshakita          #+#    #+#              #
#    Updated: 2021/01/20 18:59:13 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	*.c 

OBJ_NAME	= $(SRC:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc $(CFLAGS) -c

RM			= rm -f

${NAME}:
			${CC} ${SRC}
			ar rc $(NAME) ${OBJ_NAME}

all:		${NAME}

clean:
			${RM} ${OBJ_NAME}

fclean:		clean
			${RM} ${NAME}

re:			fclean all