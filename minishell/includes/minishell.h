/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:07:18 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 17:11:22 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <term.h>
# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	int				pid;
	int				res;
	int				status;
	int				test;
	int				tmp_i;
	int				redirect_in;
	int				redirect_out;
	int				quit;
	int				norma_besit;
	char			**arg;
	int				pp[2];
	int				type;
	struct s_list	*next;
	struct s_list	*prev;			
}					t_list;

typedef struct s_shell {
	int		code_return;
	int		pos_hist;
	int		echo_flag;
	char	name_hist[200];
	int		test_contr_c_sig;
	int		tmp_count;
	int		count_len;
	int		flag_redir;
	int		flag_bildin;
	int		ret_code;
	int		firts_new_line;
	int		child;
}				t_shell;

typedef struct s_init {
	int		i;
	char	*line_to_pars2;
	char	**my_envp;
	int		fd_hist;
	int		new_pos;
	int		new_pos_tmp;
}				t_init;

typedef struct s_bild_var {
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;
	char	buf[2000];
	int		flag_n;
	int		not_print_pipe;
}				t_bild_var;

typedef struct s_hdoc {
	int		i;
	int		fd_her;
	char	buf[2000];
	int		pid;
	int		status;
}				t_hdoc;

t_shell		g_shell;

void	ft_write_hist(char *line);
void	ft_history_updown_switch(t_init *init, char *str, char *line_to_pars);
char	**ft_my_envp(char **envp);
void	ft_shlvl(char **envp);
int		num_size(char **en);
void	delete_one_envp(char **en, int i);
char	**ft_realloc_envp(char **en, int new_size, int del_str);
void	ft_gg_wp_the_end(void);
void	ft_free_en(char ***en);
char	**ft_realloc_more_line(char ***envp, char *new_line);
char	**ft_realloc_del_one_line(char ***envp, int del);
int		ft_stat_file(char *file);
int		ft_open_zero_redirect1(t_list *list);
int		ft_zero_fork(t_list *list);

int		ft_isspec_sym(char c);
int		ft_issym(char c);
int		ft_isarg(char **arg, char *line);
int		ft_iscomma(char c);
int		skip_space(char *buf, int i);
int		ft_search_var(char **envp, char *var);
char	*ft_revers_one_dir(char *line, int len);
void	ft_history_init(char **line_hist);

/*
**      ECHO
*/
int		ft_echo(t_list *list);
int		ft_pipe_in_cd(t_bild_var *echo, t_list *list);
void	ft_check_cd_redir(t_bild_var *echo, t_list *list);
int		ft_check_flag_n(t_bild_var *echo, t_list *list);
void	ft_init_echo_var(t_bild_var *echo, t_list *list);
int		ft_echo_str(t_list *list, char *buf);
void	ft_init_echo_str_var(t_bild_var *echo_str, int code);
int		ft_pwd(char ***envp, t_list *list);

/*
**      CD
*/
int		ft_cd(char ***envp, t_list *list);
int		ft_check_redir_cd(t_bild_var *cd, t_list *list);
void	ft_some_cd_while(t_bild_var *cd, t_list *list);
int		ft_only_cd_and_no_pipe(t_bild_var *cd, t_list *list, char ***envp);
int		ft_cd_pipe(t_bild_var *cd, t_list *list, char ***envp);
void	ft_first_cd_utils(t_bild_var *cd, t_list *list, char ***envp);
void	ft_second_cd_utils_patt_two(t_bild_var *cd, t_list *list, \
			char ***envp);
int		ft_second_cd_utils(t_bild_var *cd, t_list *list, char ***envp);
int		ft_unset(char ***envp, t_list *list);
void	ft_cd_unset_fork(t_list *list);

/*
**      EXPORT
*/
void	ft_export_sort(char **my_envp, int count_envp);
int		ft_export(char ***envp, t_list *list);
void	ft_export_print(char *str, int fd);
void	ft_export_print1(char *str, int fd);
void	ft_export_print2(char *str, int fd);
int		ft_export_work1(t_list *list, char ***envp, int *j, int i);
//		ENV
int		ft_env(char ***envp, t_list *list);
int		ft_check_ravno(char *arg);

/*
**      DOLLAR
*/
int		ft_check_dollar(char ***envp, char *line);
int		ft_dollar(char ***envp, char *line);
int		ft_strlen_ravno(char *env, char *buf);
void	ft_donald_baks(char **envp, t_list *list);
void	ft_dollar_exit_status_cmp(char *buf, int *j);
int		ft_one_comma_cmp(char *arg, char *buf, int *i, int *j);
char	**ft_del_arg_list(t_list *list, int del);
int		ft_cpy_code_ret(char *buf, t_shell *shell);
void	ft_envpcpy(char *buf, char *en);
int		ft_two_comma_cmp_1(char **envp, char *arg, char *buf, int *i);
int		ft_two_comma_cmp(char **envp, char *arg, char *buf, int *i);
int		ft_dollar_cmp_1(char **envp, char *arg, char *buf, int *i);
int		ft_dollar_cmp(char **envp, char *arg, char *buf, int *i);

/*
**      Execve
*/
int		ft_execve_call(t_list *list, char ***envp);
int		ft_sys_check_command_2_1(t_list *list, char *buf, char **path);
int		ft_sys_check_command_1(t_list *list, char **path, struct stat *bufst);
int		ft_sys_check_command_2(t_list *list, char **path);
int		ft_sys_check_command_3_1(t_list *list, char **tmp_path);
int		ft_sys_check_command_3(t_list *list, char **envp, char **path, int i);
int		ft_sys_check_command(t_list *list, char **envp, char **path, \
						struct stat *bufst);
int		ft_sys_pipe(t_list *list);
void	ft_set_term(int option);
int		ft_search_slash(char *arg);
void	ft_execve_pid_null(t_list *list, char **envp, int *fd, char *path);

int		ft_check_minishell(char *command);

/*
**      LINE Parse
*/
char	**ft_split_line(char ***envp, char *line);
int		ft_num_pipe(char *line, int i, int count);
int		ft_check_arg_zero(char ***envp, char *line, char *buf);
int		ft_comma_buf_cmp(char *line, char *buf, int *i, char comma);
void	ft_check_arg_zero_comma(char *line, char *buf, int *i, int *j);
void	ft_check_arg_zero1(char *line, char *buf, int *i, int *j);
void	ft_check_arg_zero2(char ***envp, char *line, int *i);

/*
**      REDIRECT
*/	
int		ft_redirect_in(t_list *list, char *stop);
void	ft_hdoc_print_or_exit(t_hdoc *hdoc, int code);
void	ft_hdoc_utils(t_hdoc *hdoc, int code);
int		ft_redirect_output(t_list *list, int i);
int		ft_redirect_input(t_list *list, int i);
int		ft_check_redirect(t_list *list, int i);
void	ft_free_arg_redirect(t_list *list, int i);
int		ft_open_zero_redirect(t_list *list);
int		ft_syntax_red_err(t_list *list, int i);
void	ft_redirect_sort(t_list *list);
int		ft_redirect_error(t_list *list, int i, int pp);
int		ft_system_redirect(t_list *list, int *fdre0, int *fdre1);
int		ft_red_in(t_list *list, int i);
int		ft_red_out(t_list *list, int i);
int		ft_check_red_in(char *arg);
int		ft_check_red_out(char *arg);

/*
**      PIPE
*/
int		ft_num_arg(char *line, int *count);
void	ft_fork_bildin(t_list *list);
void	ft_fork_bildin2(t_list *list);
int		ft_fork_zero(t_list *list);

/*
**      LISTs
*/
t_list	*ft_create_list(t_list *tmp, char *str);
void	ft_all_list_free(t_list *list);
int		ft_pars_00(char *line_to_pars, char ***envp);
int		ft_init_pars_var(t_list **list, t_list **tmps, char *line_to_pars);
void	ft_parse_loop(t_list **p_list, t_list **tmps, char ***envp, int *code);
void	ft_run_cmd(t_list *list, char ***envp, int *code);
void	ft_pars_wait(t_list *list);
int		ft_symb_redir_cmp(char *str, char *buf, int *j, char symb);

/*
**      NEW PARS LINE IN LIST
*/
int		ft_one_line_pipe_1(char *line, char *buf, int j);
int		ft_one_arg_1(char *str, char *buf, int j, int i);
char	**ft_split_arg_1(char *str);
char	**ft_split_pipe_1(char *line, int num);
t_list	*ft_choto_list_1(char *line, int i, int num);

/*
**      signals
*/
void	sig_quit(int code);
void	for_signal(int sig);
void	for_signal_fork(int sig);
void	for_signal_her(int sig);

/*
**      main
*/
void	ft_shell_init(t_init *init, char **envp);
void	ft_make_loop_param(t_init *init);
void	ft_delete_symbol(void);
int		ft_make_line(char *str, t_init *init, char *line_to_pars);
int		ft_minishell_heart(t_init *init, char *str, char *line_to_pars);
void	ft_shell_live(char *str, char *line_to_pars, t_init *init);

/*
**      EXIT
*/
void	ft_exit(char *str1, char *str2, char *str3, int code);
int		ft_exit_shell(t_list *list);

#endif
