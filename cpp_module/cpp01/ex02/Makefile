# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 12:48:46 by eshakita          #+#    #+#              #
#    Updated: 2021/09/01 12:53:44 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= brain

SRC			= main.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

CC			= clang++ -Wall -Wextra -Werror

RM			= rm -f

.c.o:
			$(CC) -c $< -o $(<:.cpp=.o

all:		$(NAME)

$(NAME):	$(OBJ_NAME) 
			$(CC) $^ -o $@

clean:		
			$(RM) $(OBJ_NAME)

fclean:		clean
			$(RM) ${NAME}

re:			fclean all