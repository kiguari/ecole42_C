# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 12:42:50 by eshakita          #+#    #+#              #
#    Updated: 2021/09/17 10:36:44 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= zombie

SRC			= newZombie.cpp randomChumb.cpp main.cpp Zombie.cpp

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