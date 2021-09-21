# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 13:35:11 by eshakita          #+#    #+#              #
#    Updated: 2021/09/16 17:33:21 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

SRC			= ContactClass.cpp PhonebookClass.cpp main.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

INCLUDE		= ContactClass.hpp PhonebookClass.hpp

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
