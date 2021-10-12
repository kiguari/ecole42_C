# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 12:31:05 by eshakita          #+#    #+#              #
#    Updated: 2021/10/08 15:39:07 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= materia

SRC			= main.cpp AMateriaClass.cpp CharacterClass.cpp CureClass.cpp IceClass.cpp MateriaSourceClass.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= AMateriaClass.hpp CharacterClass.hpp CureClass.hpp IceClass.hpp ICharacterClass.hpp IMateriaSourceClass.hpp MateriaSourceClass.hpp

CC			= clang++ -Wall -Wextra -Werror -std=c++98

RM			= rm -f

%.o: %.cpp 	$(INCLUDE)
			$(CC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ_NAME) 
			$(CC) $^ -o $@

clean:		
			$(RM) $(OBJ_NAME)

fclean:		clean
			$(RM) ${NAME}

re:			fclean all