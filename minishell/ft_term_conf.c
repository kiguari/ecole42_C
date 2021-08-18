/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_conf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:09:49 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 13:10:09 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_set_term(int option)
{
	struct termios	term;

	if (option == 1)
	{
		tcgetattr(0, &term);
		term.c_lflag &= ~(ECHO | ICANON);
		term.c_cc[VEOF] = 4;
		tcsetattr(0, TCSANOW, &term);
		if (tgetent(0, getenv("TERM")))
			tgetent(0, "xterm-256color");
		tputs(save_cursor, 1, &ft_putchar);
	}
	if (option == 2)
	{
		tcgetattr(0, &term);
		term.c_lflag |= (ECHO | ICANON);
		tcsetattr(0, TCSANOW, &term);
	}
}
