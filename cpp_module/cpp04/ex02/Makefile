# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 12:31:05 by eshakita          #+#    #+#              #
#    Updated: 2021/10/06 16:53:41 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Abstract

SRC			= main.cpp CatClass.cpp AnimalClass.cpp DogClass.cpp WrongAnimalClass.cpp WrongCatClass.cpp BrainClass.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= CatClass.hpp AnimalClass.hpp DogClass.hpp WrongAnimalClass.hpp WrongCatClass.hpp BrainClass.hpp

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