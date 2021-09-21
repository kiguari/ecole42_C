# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 11:31:45 by eshakita          #+#    #+#              #
#    Updated: 2021/09/21 14:14:59 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= DiamondTrap

SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

CC			= clang++ -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

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