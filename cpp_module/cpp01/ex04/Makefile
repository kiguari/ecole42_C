# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 13:07:31 by eshakita          #+#    #+#              #
#    Updated: 2021/09/17 11:18:38 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= replace

SRC			= main.cpp

OBJ_NAME	= $(SRC:.cpp=.o)

CC			= clang++ -Wall -Wextra -Werror -std=c++98

RM			= rm -f

%.o: %.cpp 	
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ_NAME) 
			$(CC) $^ -o $@

clean:		
			$(RM) $(OBJ_NAME)

fclean:		clean
			$(RM) ${NAME}

re:			fclean all