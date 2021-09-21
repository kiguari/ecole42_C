# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 13:07:31 by eshakita          #+#    #+#              #
#    Updated: 2021/09/17 10:37:42 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Unnecessary_violence

SRC			= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

INCLUDE		= HumanA.hpp HumanB.hpp Weapon.hpp

OBJ_NAME	= $(SRC:.cpp=.o)

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