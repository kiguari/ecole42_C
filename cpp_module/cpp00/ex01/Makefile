# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 13:35:11 by eshakita          #+#    #+#              #
#    Updated: 2021/09/14 17:20:54 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

SRC			= contact_class.cpp phonebook_class.cpp main.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= contact_class.hpp phonebook_class.hpp

CC			= clang++ -Wall -Wextra -Werror -std=c++98

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
