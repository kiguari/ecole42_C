# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 11:31:45 by eshakita          #+#    #+#              #
#    Updated: 2021/09/08 11:10:57 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= FragTrap

SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

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