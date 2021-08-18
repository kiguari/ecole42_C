/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:04:31 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 16:33:56 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_shell_init(t_init *init, char **envp)
{
	struct termios	term;
	const char		*tern_name = "xterm-256color";

	init->i = 0;
	init->new_pos = 0;
	init->new_pos_tmp = 0;
	g_shell.pos_hist = 0;
	g_shell.code_return = 0;
	g_shell.echo_flag = 1;
	g_shell.child = 0;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, tern_name);
	init->my_envp = ft_my_envp((char **)envp);
	ft_shlvl(init->my_envp);
	ft_history_init(&init->line_to_pars2);
}

int	main(int argc, char **argv, char const **envp)
{
	t_init	init;
	char	*norma_flag_bah;
	char	str[1000];
	char	line_to_pars[1000];

	norma_flag_bah = argv[argc];
	ft_shell_init(&init, (char **)envp);
	ft_shell_live(str, line_to_pars, &init);
	write(1, "exit\n", 5);
	exit (0);
}
