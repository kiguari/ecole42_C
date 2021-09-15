# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 12:31:05 by eshakita          #+#    #+#              #
#    Updated: 2021/09/08 16:15:05 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Polymorphizm

SRC			= main.cpp CatClass.cpp AnimalClass.cpp DogClass.cpp WrongAnimalClass.cpp WrongCatClass.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= CatClass.hpp AnimalClass.hpp DogClass.hpp WrongAnimalClass.hpp WrongCatClass.hpp

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