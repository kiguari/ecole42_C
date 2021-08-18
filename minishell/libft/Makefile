# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 13:41:49 by tmagikar          #+#    #+#              #
#    Updated: 2021/08/09 18:37:01 by tmagikar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

INCLUDE 	= libft.h

SRC =		ft_atoi.c\
			ft_bzero.c\
			ft_fullzero.c \
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_split.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_itoa.c\
			ft_strcmp.c \
			ft_strcpy.c \
			ft_free_dou_array.c \
			get_next_line.c \

OBJ_NAME	= $(SRC:.c=.o)

all:		${NAME}

${NAME}:	${OBJ_NAME}
# ${CC} ${SRC}
			ar rc $(NAME) ${OBJ_NAME}

# $(OBJS):	$(HEADER)

clean:
			${RM} ${OBJ_NAME}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
