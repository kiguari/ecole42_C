# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 13:41:49 by tmagikar          #+#    #+#              #
#    Updated: 2021/04/02 15:36:31 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

INCLUDE = 	libft.h

SRC =		ft_isdigit.c ft_split.c ft_strdup.c ft_substr.c ft_strlen.c ft_atoi.c ft_memcmp.c ft_strjoin.c \			

OBJ_NAME	= $(SRC:.c=.o)

CFLAGS		= -Wall -Wextra -Werror -c

CC			= gcc $(CFLAGS)

RM			= rm -f

$(NAME):
			$(CC) $(SRC)
			ar rc $(NAME) $(OBJ_NAME)

all:		$(NAME) $(INCLUDE)

clean:
			$(RM) $(OBJ_NAME)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
