# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 11:31:45 by eshakita          #+#    #+#              #
#    Updated: 2021/09/08 10:59:35 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= DiamondTrap

SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

CC			= clang++ -Wall -Wextra -Werror -Wshadow -Wno-shadow

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