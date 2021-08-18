#SETUP

NAME		= minishell

INCLUDE		= includes/minishell.h

#FILES
SRC			= main.c \
				ft_parse.c \
				ft_dollar.c \
				ft_envp.c \
				ft_envp_utils.c \
				ft_envp_utils_continue.c \
				ft_global_utils.c \
				ft_global_utils_continue.c \
				ft_global_utils_coninue_path_two.c \
				ft_global_utils_hdoc.c \
				ft_echo.c \
				ft_export.c \
				ft_export_utils.c \
				ft_pwd.c \
				ft_unset.c \
				ft_execve_call.c \
				ft_execve_check_command.c \
				ft_execve_fork.c \
				ft_check_line.c \
				ft_check_line_utils.c \
				ft_check_line_utils2.c \
				ft_pipe.c \
				ft_creat_list.c \
				ft_creat_list_utils.c \
				ft_term_conf.c \
				ft_realloc.c \
				ft_cd.c \
				ft_check_dollar.c \
				ft_check_dollar_utils.c \
				ft_check_dollar_utils2.c \
				ft_exit_shell.c \
				ft_redirect.c \
				ft_redirect_pipe.c \
				ft_redirect_pipe_utils.c \
				ft_redirect_utils.c \
				ft_redirect_utils_continue.c \
				ft_signals.c \
				ft_history.c \
				ft_minishell_loop.c \
				ft_cd_utils.c \
				ft_echo_utils.c \

OBJ_NAME	= $(SRC:.c=.o)

CC			= gcc -g -Wall -Wextra -Werror
# CC			= gcc -g #-fsanitize=address
RM			= rm -f

DOP			= -ltermcap

LIBFT		= libft/libft.a
LIBFT_DIR	= libft/

HIST_FILE	= .minishell_history

all:		tools $(NAME)

$(NAME):	$(LIBFT) $(OBJ_NAME) includes/minishell.h START
			@$(CC) -o $(NAME) $(DOP) $(LIBFT) $(OBJ_NAME)

bonus:		$(NAME)

%.o:		%.c
			$(CC) -c -o $@ $<
			printf "$(WHITE)it's not relink, trust me..\n\n"
tools:
			@$(MAKE) -C $(LIBFT_DIR)

clean:		CLEAN
			$(RM) $(OBJ_NAME)
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) ${NAME}
			$(RM) $(LIBFT)
			$(RM) $(HIST_FILE)

# добавил при fclean удаление истории

re:			fclean all

.SILENT:
START:
	echo "$(GREEN)\n\t Tmagikar & Eshakita MINIGOOSE COMPILING - wait!"
	sleep 0.3
	echo "$(GREEN)\t\t     we make history here\n"
	sleep 0.3
	echo "$(GREEN)\t\t MINIGUS tools:"
	echo "$(GREEN)\t\t flags: -Wall -Wextra -Werror\n"
	sleep 0.3
	echo "$(RED)\t !!!WARNING!!! minishell transformation to ...\n" 
	sleep 2
	echo "$(RED)\t\t <<<MINIGOOSE>>>"
	sleep 1
	echo "$(WHITE)"
	sleep 0.3
	bash goose/.re.bash
	echo "$(GREEN)\t\t MINIGOOSE COMPILED GOOD LUCK!!!\n"

CLEAN:
	echo "$(GREEN)\n\t delete $(NAME) COMPILING - wait!\n"
	
GREEN = \033[1;32m
WHITE = \033[1;37m
RED = \033[1;31m