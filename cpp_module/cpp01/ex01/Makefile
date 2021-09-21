# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 12:45:03 by eshakita          #+#    #+#              #
#    Updated: 2021/09/17 10:36:40 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= zombie

SRC			= Zombie.cpp ZombieHorde.cpp main.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= Zombie.hpp

CC			= clang++ -Wall -Wextra -Werror -std=c++98

RM			= rm -f

%.o: %.cpp 	$(INCLUDE)
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ_NAME) 
			$(CC) $^ -o $@

clean:		
			$(RM) $(OBJ_NAME)

fclean:		clean
			$(RM) ${NAME}

re:			fclean all