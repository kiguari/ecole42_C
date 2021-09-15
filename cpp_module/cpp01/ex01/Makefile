# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 12:45:03 by eshakita          #+#    #+#              #
#    Updated: 2021/09/01 12:45:24 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= zombie

SRC			= Zombie.cpp ZombieHorde.cpp main.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= Zombie.hpp

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