/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:03:24 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/21 18:44:55 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flag
{
	int			minus;
	int			plus;
	int			nool;
	int			tochka;
	int			shirina;
	int			tochnost;
	int			space;
	int			d_shiri;
	int			d_tochn;
	int			shiri_u;
	int			tochn_u;
	int			tk;
}				t_flag;

typedef struct	s_sprs
{
	long int	d;
	char		c;
	char		*s;
	void		*p;
	int			u;
	int			x;
	char		percent;
}				t_sprs;

size_t			ft_strlen(const char *s);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putnchar(char c, int i);
void			ft_putstr(char *str);
int				ft_putstr_2(char *str);
int				ft_isdigit(int c);
char			*ft_itoa_16h_p(size_t *n);
char			*ft_itoa_16h_x(int n, char *point);
int				len_numb(const long long int d);
int				len_numb_uns(unsigned int d);
int				ft_putnbr_uns(unsigned int nb);
int				ft_putnbr_uns_u(unsigned int nb, t_flag *znak);
int				ft_check_flag(int point);
char			*ft_flag(char *point, t_flag *znak);
void			ft_flag_null(t_flag *znak);
char			*ft_pars(char *point, t_flag *znak, va_list *name);
int				sign(const int d, t_flag *znak);
int				print_d_i(const int d, t_flag *znak);
int				ft_m_d_tc(t_flag *znak, int d, int n, int size_of_d_i);
int				ft_nm_d_n_tochn(t_flag *znak, int d, int n);
int				ft_nm_d_tc(t_flag *znak, int d, int n, int size_of_d_i);
int				ft_nm_d_nt_dop(t_flag *znak, int d, int n, int size_of_d_i);
int				print_str(const char *s, t_flag *znak);
int				print_u(int u, t_flag *znak);
int				ft_nm_u_tc(t_flag *znak, int n, int u, int size_of_u);
int				ft_nm_u_nt(t_flag *znak, int n, int u, int size_of_u);
int				ft_nm_u(t_flag *znak, int n, int u, int size_of_u);
int				print_x(int x, t_flag *znak, char *point);
int				ft_x(t_flag *znak, int size_of_x, char *dec_16, int super_test);
int				ft_m_nt_x(t_flag *znak, char *line, int n, int size_x);
int				ft_m_t_x(t_flag *znak, char *line, int n, int size_x);
int				ft_nm_nt_x(t_flag *znak, char *line, int n, int size_x);
int				ft_nm_t_x_a(t_flag *znak, int n, char *line);
int				ft_nm_t_x(t_flag *znak, char *line, int n, int size_x);
char			*ft_adress(size_t *adr);
int				print_c(int c, t_flag *znak);
int				print_p(size_t *p, t_flag *znak);
int				ft_m_p_a(t_flag *znak, int n);
int				print_percent(int c, t_flag *znak);
int				print_c2(int c, t_flag *znak);
int				ft_printf(const char *points, ...);

#endif
