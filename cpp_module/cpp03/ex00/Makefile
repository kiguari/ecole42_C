# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 11:31:45 by eshakita          #+#    #+#              #
#    Updated: 2021/09/20 19:18:24 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ClapTrap

SRC			= main.cpp ClapTrap.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= ClapTrap.hpp

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