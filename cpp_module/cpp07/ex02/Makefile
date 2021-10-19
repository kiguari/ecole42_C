# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 12:31:05 by eshakita          #+#    #+#              #
#    Updated: 2021/10/19 11:47:06 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= array

SRC			= main.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= Array.hpp

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