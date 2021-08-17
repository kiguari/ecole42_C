#include "ft_printf.h"
#include "ft_printf.c"
#include "func_gen.c"
#include "func_gen2.c"
#include "func_gen3.c"
#include "func_for_p.c"
#include "func_for_x.c"
#include "func_for_u.c"
#include "func_for_d_i.c"
#include "print_d_i.c"
#include "ft_flag.c"
#include "print_str.c"
#include "print_u.c"
#include "print_x.c"
#include "print_c.c"
#include "print_c2.c"
#include "print_p.c"
#include "print_percent.c"
#include "ft_pars.c"
//#include "print_no.c"
#include <stdio.h>


//int main(void)
//{
	// printf("\n");
	// ft_printf("for_d_and_i:\n");
    // printf("-----------------");
	// printf("\n");
	// printf("|or:%d|", 5); printf("|or:%-d|", 5); printf("|or:%-d %-d %-d|", 5, 5, 5); printf("|or:%d %d %d|", 5, 5, 5); printf("|or:d|");
	// printf("\n");
    // ft_printf("|my:%d|", 5); ft_printf("|my:%-d|", 5); ft_printf("|my:%-d %-d %-d|", 5, 5, 5); ft_printf("|my:%d %d %d|", 5, 5, 5); ft_printf("|my:d|");
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%3d|", 5);  printf("|or:%-3d|", 5); printf("|or:%-.3d|", 5); printf("|or:%.3d|", 5); printf("|or:%3.3d|", 5); printf("|or:%-3.3d|", 5); printf("|or:%05d|", 5); printf("|or:%-.5d|", 5);
	// printf("\n");
    // ft_printf("|my:%3d|", 5); ft_printf("|my:%-3d|", 5); ft_printf("|my:%-.3d|", 5); ft_printf("|my:%.3d|", 5); ft_printf("|my:%3.3d|", 5); ft_printf("|my:%-3.3d|", 5); ft_printf("|my:%05d|", 5); ft_printf("|my:%-.5d|", 5);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%0.5d|", 5); printf("|or:%05d|", 5); printf("|or:%0.0d|", 5); printf("|or:%5.6d|", 5); printf("|or:d|"); printf("|or:%-.5d|", 5); printf("|or:%-5.5d|", 5);
	// printf("\n");
    // ft_printf("|my:%0.5d|", 5); ft_printf("|my:%05d|", 5); ft_printf("|my:%0.0d|", 5); ft_printf("|my:%5.6d|", 5); ft_printf("|my:d|"); ft_printf("|my:%-.5d|", 5); ft_printf("|my:%-5.5d|", 5);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%6.5d|", 5); printf("|or:%.5d|", 5); printf("|or:%5.6d|", 5); printf("|or:d|"); printf("|or:%-.5d|", 5); printf("|or:%-5.5d|", 5);
	// printf("\n");
    // ft_printf("|my:%6.5d|", 5); ft_printf("|my:%.5d|", 5); ft_printf("|my:%5.6d|", 5); ft_printf("|my:d|"); ft_printf("|my:%-.5d|", 5); ft_printf("|my:%-5.5d|", 5);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%+03d|", 5); printf("|or:%+8.5d|", 5); printf("|or:%+.5d|", 5); printf("|or:%+6d|", 5); printf("|or:%+d|", 5); printf("|or:%d|", -5); printf("|or:%-d|", -5);
	// printf("\n");
	// ft_printf("|my:%+03d|", 5); ft_printf("|my:%+8.5d|", 5); ft_printf("|my:%+.5d|", 5); ft_printf("|my:%+6d|", 5); ft_printf("|my:%+d|", 5); ft_printf("|my:%d|", -5); ft_printf("|my:%-d|", -5);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:% 03d|", 5); printf("|or:%03d|", 5); printf("|or:% .5d|", 5); printf("|or:% 6d|", 5); printf("|or:%3.3d|", -5); printf("|or:%d|", -5); printf("|or:%- d|", -5); printf("|or:%6.3d|", -5); printf("|or:%-6.3d|", -5); 
	// printf("\n");
	// ft_printf("|my:% 03d|", 5); ft_printf("|my:%03d|", 5); ft_printf("|my:% .5d|", 5); ft_printf("|my:% 6d|", 5); ft_printf("|my:%3.3d|", -5); ft_printf("|my:%d|", -5); ft_printf("|my:%- d|", -5); ft_printf("|my:%6.3d|", -5); ft_printf("|my:%-6.3d|", -5); 
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%-*.*d|", 7, 6, 5); printf("|or:%*d|", 7, 5); printf("|or:%-*.6d|", 7, 5); printf("|or:%-6.*d|", 7, 5); printf("|or:% *d|", 7, -5); printf("|or:%0*d|", 7, -5); printf("|or:%-*.*d|", 7, 7, -5); printf("|or:%6.3d|", -5); 
	// printf("\n");
	// ft_printf("|my:%-*.*d|", 7, 6, 5); ft_printf("|my:%*d|", 7, 5); ft_printf("|my:%-*.6d|", 7, 5); ft_printf("|my:%-6.*d|", 7, 5); ft_printf("|my:% *d|", 7, -5); ft_printf("|my:%0*d|", 7, -5); ft_printf("|my:%-*.*d|", 7, 7, -5); ft_printf("|my:%6.3d|", -5); 
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");
	
	// printf("for_s:");
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");
	// printf("|or:%.s|", "qwe"); printf("|or:%s|", "qwe"); printf("|or:%-s|", "qwe"); printf("|or:%.10s|", "qwe"); printf("|or:%s|", "qwe");
	// printf("\n");
	// ft_printf("|my:%.s|", "qwe"); ft_printf("|my:%s|", "qwe"); ft_printf("|my:%-s|", "qwe"); ft_printf("|my:%.10s|", "qwe"); ft_printf("|my:%s|", "qwe");
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%1.1s|", "qwe"); printf("|or:%5.5s|", "qwe"); printf("|or:%7.5s|", "qwe"); printf("|or:%5.7s|", "qwe"); printf("|or:%-7.5s|", "qwe"); printf("|or:%7.5s|", "qwe");
	// printf("\n");
	// ft_printf("|my:%1.1s|", "qwe"); ft_printf("|my:%5.5s|", "qwe"); ft_printf("|my:%7.5s|", "qwe"); ft_printf("|my:%5.7s|", "qwe"); ft_printf("|my:%-7.5s|", "qwe"); ft_printf("|my:%7.5s|", "qwe");
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%c|", ':'); printf("|or:%5.5s|", "qwe"); printf("|or:%7.5s|", "qwe"); printf("|or:%5.7s|", "qwe"); printf("|or:%-7.5s|", "qwe"); printf("|or:%7.5s|", "qwe");
	// printf("\n");
	// ft_printf("|my:%c|", ':'); ft_printf("|my:%5.5s|", "qwe"); ft_printf("|my:%7.5s|", "qwe"); ft_printf("|my:%5.7s|", "qwe"); ft_printf("|my:%-7.5s|", "qwe"); ft_printf("|my:%7.5s|", "qwe");
	// printf("\n");
	// printf("|or:%*.*c|", -4, 0, ':'); printf("|or:%5.5s|", "qwe"); printf("|or:%7.5s|", "qwe"); printf("|or:%5.7s|", "qwe"); printf("|or:%-7.5s|", "qwe"); printf("|or:%7.5s|", "qwe");
	// printf("\n");
	// ft_printf("|my:%*.*c|", -4, 0, ':'); ft_printf("|my:%5.5s|", "qwe"); ft_printf("|my:%7.5s|", "qwe"); ft_printf("|my:%5.7s|", "qwe"); ft_printf("|my:%-7.5s|", "qwe"); ft_printf("|my:%7.5s|", "qwe");
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");

	// ft_printf("for_u:\n");
    // printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");
	// printf("|or:%u|", 5); printf("|or:%-u|", 5); printf("|or:%-u %-u %-u|", 5, 5, 5); printf("|or:%u %u %u|", 5, 5, 5); printf("|or:u|");
	// printf("\n");
    // ft_printf("|my:%u|", 5); ft_printf("|my:%-u|", 5); ft_printf("|my:%-u %-u %-u|", 5, 5, 5); ft_printf("|my:%u %u %u|", 5, 5, 5); ft_printf("|my:u|");
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%3u|", 5);  printf("|or:%-3u|", 5); printf("|or:%-.3u|", 5); printf("|or:%.3u|", 5); printf("|or:%3.3u|", 5); printf("|or:%-3.3u|", 5); printf("|or:%05u|", 5); printf("|or:%-.5u|", 5);
	// printf("\n");
    // ft_printf("|my:%3u|", 5); ft_printf("|my:%-3u|", 5); ft_printf("|my:%-.3u|", 5); ft_printf("|my:%.3u|", 5); ft_printf("|my:%3.3u|", 5); ft_printf("|my:%-3.3u|", 5); ft_printf("|my:%05u|", 5); ft_printf("|my:%-.5u|", 5);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%0.5u|", 5); printf("|or:%05u|", 5); printf("|or:%0.0u|", 5); printf("|or:%5.6u|", 5); printf("|or:u|"); printf("|or:%-.5u|", 5); printf("|or:%-5.5u|", 5);
	// printf("\n");
    // ft_printf("|my:%0.5u|", 5); ft_printf("|my:%05u|", 5); ft_printf("|my:%0.0u|", 5); ft_printf("|my:%5.6u|", 5); ft_printf("|my:u|"); ft_printf("|my:%-.5u|", 5); ft_printf("|my:%-5.5u|", 5);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%6.5u|", 5); printf("|or:%.5u|", 5); printf("|or:%5.6u|", 5); printf("|or:u|"); printf("|or:%-.5u|", 5); printf("|or:%-5.5u|", 5);
	// printf("\n");
    // ft_printf("|my:%6.5u|", 5); ft_printf("|my:%.5u|", 5); ft_printf("|my:%5.6u|", 5); ft_printf("|my:u|"); ft_printf("|my:%-.5u|", 5); ft_printf("|my:%-5.5u|", 5);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%03u|", 5); printf("|or:%8.5u|", 5); printf("|or:%.5u|", 5); printf("|or:%6u|", 5); printf("|or:%u|", 5); printf("|or:%u|", -5); printf("|or:%-u|", -5);
	// printf("\n");
	// ft_printf("|my:%03u|", 5); ft_printf("|my:%8.5u|", 5); ft_printf("|my:%.5u|", 5); ft_printf("|my:%6u|", 5); ft_printf("|my:%u|", 5); ft_printf("|my:%u|", -5); ft_printf("|my:%-u|", -5);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%03u|", 5); printf("|or:%03u|", 5); printf("|or:%.5u|", 5); printf("|or:%6u|", 5); printf("|or:%3.3u|", -5); printf("|or:%u|", -5); printf("|or:%u|", -5); printf("|or:%6.3u|", -5); printf("|or:%-6.3u|", -5); 
	// printf("\n");
	// ft_printf("|my:%03u|", 5); ft_printf("|my:%03u|", 5); ft_printf("|my:%.5u|", 5); ft_printf("|my:%6u|", 5); ft_printf("|my:%3.3u|", -5); ft_printf("|my:%u|", -5); ft_printf("|my:%u|", -5); ft_printf("|my:%6.3u|", -5); ft_printf("|my:%-6.3u|", -5); 
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%-*.*u|", 7, 6, 5); printf("|or:%*u|", 7, 5); printf("|or:%-*.6d|", 7, 5); printf("|or:%-6.*u|", 7, 5); printf("|or:%*u|", 7, -5); printf("|or:%0*u|", 7, -5); printf("|or:%-*.*u|", 7, 7, -5); printf("|or:%6.3u|", -5); 
	// printf("\n");
	// ft_printf("|my:%-*.*u|", 7, 6, 5); ft_printf("|my:%*u|", 7, 5); ft_printf("|my:%-*.6d|", 7, 5); ft_printf("|my:%-6.*u|", 7, 5); ft_printf("|my:%*u|", 7, -5); ft_printf("|my:%0*u|", 7, -5); ft_printf("|my:%-*.*u|", 7, 7, -5); ft_printf("|my:%6.3u|", -5); 
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%10u|", 100); printf("|or:%u|", -100); printf("|or:%-10u|", 100); printf("|or:%5.5u|", -100); printf("|or:%05.5u|", -100); printf("|or:%05.5u|", 100); printf("|or:%05.5u|", 0);
	// printf("\n"); 
	// ft_printf("|my:%10u|", 100); ft_printf("|my:%u|", -100); ft_printf("|my:%-10u|", 100); ft_printf("|my:%5.5u|", -100); ft_printf("|my:%05.5u|", -100); ft_printf("|my:%05.5u|", 100); ft_printf("|my:%05.5u|", 0);
	// printf("\n");
	// printf("|or:%10u|", 100); printf("|or:%u|", -100); printf("|or:%10u|", 100); printf("|or:%5.5u|", -100); printf("|or:%5.5u|", -100); printf("|or:%05.5u|", 100); printf("|or:%05.5u|", 0);
	// printf("\n"); 
	// ft_printf("|my:%10u|", 100); ft_printf("|my:%u|", -100); ft_printf("|my:%10u|", 100); ft_printf("|my:%5.5u|", -100); ft_printf("|my:%5.5u|", -100); ft_printf("|my:%05.5u|", 100); ft_printf("|my:%05.5u|", 0);
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");


	// ft_printf("for_x_and_X:");
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");
	// printf("|or:%x|", 16); printf("|or:%x|", 260); printf("|or:%x|", 1008);
	// printf("\n"); 
	// ft_printf("|my:%x|", 16); ft_printf("|my:%x|", 260); ft_printf("|my:%x|", 1008);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%10.9x|", 16); printf("|or:%-x|", 260); printf("|or:%x|", 1008);
	// printf("\n"); 
	// ft_printf("|my:%10.9x|", 16); ft_printf("|my:%-x|", 260); ft_printf("|my:%x|", 1008);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%-10.9x|", 16); printf("|or:%-x|", 260); printf("|or:%x|", 1008);
	// printf("\n"); 
	// ft_printf("|my:%-10.9x|", 16); ft_printf("|my:%-x|", 260); ft_printf("|my:%x|", 1008);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%10.9x|", 16); printf("|or:%x|", 260); printf("|or:%x|", 1008);
	// printf("\n"); 
	// ft_printf("|my:%10.9x|", 16); ft_printf("|my:%x|", 260); ft_printf("|my:%x|", 1008);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%*.*x|", 10, 9, 16); printf("|or:%x|", 260); printf("|or:%x|", 1008);
	// printf("\n"); 
	// ft_printf("|my:%*.*x|", 10, 9, 16); ft_printf("|my:%x|", 260); ft_printf("|my:%x|", 1008);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:%*.*X|", 10, 9, 16); printf("|or:%X|", 260); printf("|or:%X|", 1008);
	// printf("\n"); 
	// ft_printf("|my:%*.*X|", 10, 9, 16); ft_printf("|my:%X|", 260); ft_printf("|my:%X|", 1008);
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");
	


	// printf("%x", -260);
	// printf("\n"); 
	// ft_printf("%x", -260);
	// printf("\n"); 
	// ft_printf("%x", 4294967036);
	// printf("\n"); 
	// printf("%x", 4294967036);

	// int i = -10;
	// long int i_2 = -10;

	// printf("\n"); 
	// printf("\n"); 
	// printf("%x", i);
	// printf("\n"); 
	// printf("%x", i_2);
	// printf("\n"); 
	// ft_printf("%x", i);
	// printf("\n"); 
	// ft_printf("%X", i_2);
	// printf("\n"); 
	// printf("%d", 'd');
	// printf("\n"); 


	// char *a = "|%.-7d|\n";
	// printf(a, 5);
	// ft_printf(a, 5);

	// printf("for_c:");
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");
	// printf("|or:%c|", 'f'); printf("|or:%-6c|", 'f'); printf("|or:%6c|", 'f'); printf("|or:%6c|", 'f'); printf("|or:%6c|", 'f'); printf("|or:%6c|", 'f');
	// printf("\n"); 
	// ft_printf("|my:%c|", 'f'); ft_printf("|my:%-6c|", 'f'); ft_printf("|my:%6c|", 'f'); ft_printf("|my:%6c|", 'f'); ft_printf("|my:%6c|", 'f'); ft_printf("|my:%6c|", 'f');
	// printf("\n");
	// printf("\n"); 
	// printf("|or:%c|", '%'); printf("|or:%-6c|", '\n'); printf("|or:%6c|", 'f'); printf("|or:%6c|", 'f'); printf("|or:%6c|", '\n'); printf("|or:%6c|", 'f');
	// printf("\n"); 
	// ft_printf("|my:%c|", '%'); ft_printf("|my:%-6c|", '\n'); ft_printf("|my:%6c|", 'f'); ft_printf("|my:%6c|", 'f'); ft_printf("|my:%6c|", '\n'); ft_printf("|my:%6c|", 'f');
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");

	// int i;
	// printf("for_p:");
	// printf("\n");
	// printf("------------------------------------------------------------------------------------------------------");
	// printf("\n");
	// printf("|or:%-p|", &i); printf("|or:%-10.10p|", &i); printf("|or:%-15.15p|", &i);printf("|or:%-20.15p|", &i); printf("|or:%0-20.15p|", &i); printf("|or:%-020.15p|", &i); printf("|or:%-15.20p|", &i);
	// printf("\n");
	// ft_printf("|my:%-p|", &i); ft_printf("|my:%-10.10p|", &i); ft_printf("|my:%-15.15p|", &i); ft_printf("|my:%-20.15p|", &i); ft_printf("|my:%0-20.15p|", &i); ft_printf("|my:%-020.15p|", &i); ft_printf("|my:%-15.20p|", &i);
	// printf("\n");
	// printf("-----------------");
	// printf("\n");
	// printf("|or:% p|", &i); printf("|or:% 10.10p|", &i); printf("|or:% 15.15p|", &i); printf("|or:% 20.15p|", &i); printf("|or:%020.15p|", &i); printf("|or:%20.15p|", &i); printf("|or:%25.20p|", &i);
	// printf("\n");
	// ft_printf("|my:% p|", &i); ft_printf("|my:% 10.10p|", &i); ft_printf("|my:% 15.15p|", &i); ft_printf("|my:% 20.15p|", &i); ft_printf("|my:%020.15p|", &i); ft_printf("|my:%20.15p|", &i); ft_printf("|my:%25.20p|", &i);
	// printf("\n");
	// printf("\n");
	// printf("|or:%20.15p|", &i); printf("|or:%15.20p|", &i);
	// printf("\n");
	// ft_printf("|my:%20.15p|", &i); ft_printf("|my:%15.20p|", &i);
	// printf("\n");
	// printf("|or:% 20.15p|", &i);
	// printf("\n");
	// printf("|or:%20.15p|", &i);

	// //printf("|%lx|", 140732912896060);
	// int		a = 8;
	// int		b = 5;
	// char	c = 'a';
	// int		d = 2147483647;
	// int		e = -2147483648;
	// int		f = 42;
	// int		g = 25;
	// int		h = 4200;
	// int		i = 8;
	// int		j = -12;
	// int		k = 123456789;
	// int		l = 0;
	// int		m = -12345678;
	// char	*n = "abcdefghijklmnop";
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";
	// printf("|%.*p|", 0, 0);
	// printf("\n");
	// ft_printf("|%.*p|", 0, 0);
	// printf("%0*.*x|", 2, 0, 8);
	// printf("\n");
	// ft_printf("%0*.*x|", 2, 0, 8);
	// printf("\n");
	// ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j);
	// printf("\n");
	// ft_printf("%x", -12);
	// ft_printf(" --- Return : %d\n", ft_printf("%d, %d, %d, %d, %s, %c, %d, %u, %x, %X", j, k, l, m, n, c, c, j, j, j)); //T2
	// printf("\n");
	// printf("|or:%s|", "testing testing");
	// printf("\n");
	// ft_printf("hello%s", "testing");
	// printf("\n");
	// printf("|or:%-5.5%|");
	// printf("\n");
	// ft_printf("|my:%-5.5%|");
	// printf("\n");
	// printf("|or:%s|", NULL);
	// printf("\n");
	// ft_printf("|my:%-5.5%|");
	// printf("|%d|", printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d));
	// printf("\n");
	// printf("|%d|", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d));
	// printf("\n");

	// printf("|%d|", printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// printf("\n");
	// printf("|%d|", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// printf("\n");
	// printf("\n");

	// printf("|%d|", printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// printf("\n");
	// printf("|%d|", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// printf("\n");

	// printf("|%d|", printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// printf("\n");
	// printf("|%d|", ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// printf("\n");

	// printf("\n");

	// printf("|%d|", printf("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e));
	// printf("\n");
	// printf("|%d|", ft_printf("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e));
	// printf("\n");

	// printf("\n");

	// printf("|%d|", printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X,", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// printf("\n");
	// printf("|%d|", ft_printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X,", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// printf("\n");

	// printf("\n");

	// printf("|%d|", printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0));
	// printf("\n");
	// printf("|%d|", ft_printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0));
	// printf("\n");

	// printf("|%d|", printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// printf("\n");
	// printf("|%d|", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// printf("\n");
	// printf("\n");

	// printf("|%d|", printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// printf("\n");
	// printf("|%d|", ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// printf("\n");


	// printf("\n");

	// printf("|%d|", printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// printf("\n");
	// printf("|%d|", ft_printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// printf("\n");
	// printf("\n");

	// printf("|%d|", printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// printf("\n");
	// printf("|%d|", ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// printf("\n");
	
	// //ft_printf("|%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d|", i, j, k, l, m, c, e, d);

	// //printf("|%d|", printf("%d, %d, ", -5, 5));
	// // printf("\n");
	// printf("|%9.p|", NULL); printf("|%9p|", NULL); printf("|%.10p|", NULL); printf("|%9.5p|", NULL); printf("|%p|", NULL);
	// printf("\n");
	// ft_printf("|%9.p|", NULL); ft_printf("|%9p|", NULL); ft_printf("|%.10p|", NULL); ft_printf("|%9.5p|", NULL); printf("|%p|", NULL);
	// printf("\n"); 
	// printf("\n");
	// printf("|%1.p|", NULL); printf("|%1.1p|", NULL); printf("|%1.9p|", NULL); printf("|%9.5p|", NULL); printf("|%.p|", NULL);
	// printf("\n");
	// ft_printf("|%1.p|", NULL); ft_printf("|%1.1p|", NULL); ft_printf("|%1.9p|", NULL); ft_printf("|%9.5p|", NULL); printf("|%.p|", NULL);
	// printf("\n"); 

	// printf("\n");
	// printf("|%9.p|", 1234); printf("|%9p|", 1234); printf("|%.10p|", 1234); printf("|%9.2p|", 1234); printf("|%p|", 1234);
	// printf("\n");
	// ft_printf("|%9.p|", 1234); ft_printf("|%9p|", 1234); ft_printf("|%.10p|", 1234); ft_printf("|%9.2p|", 1234); printf("|%p|", 1234);
	// printf("\n"); 

	// printf("\n");
	// printf("|%9.p|", &j); printf("|%9p|", &j); printf("|%.10p|", &j); printf("|%9.5p|", &j); printf("|%p|", &j);
	// printf("\n");
	// ft_printf("|%9.p|", &j); ft_printf("|%9p|", &j); ft_printf("|%.10p|", &j); ft_printf("|%9.5p|", &j); printf("|%p|", &j);
	// printf("\n"); 
	// printf("|%15.3p|", 1234);
	// printf("\n"); 
	// ft_printf("|%15.3p|", 1234);
	// printf("\n"); 

//	printf("|%-9.p|", NULL); printf("|%-9p|", NULL); printf("|%-.10p|", NULL); printf("|%-9.5p|", NULL); printf("|%-p|", NULL);
//	printf("\n");
//	ft_printf("|%-9.p|", NULL); ft_printf("|%-9p|", NULL); ft_printf("|%-.10p|", NULL); ft_printf("|%-9.5p|", NULL); printf("|%-p|", NULL);
//	printf("\n"); 
//	printf("\n");
//	printf("|%-1.p|", NULL); printf("|%-1.1p|", NULL); printf("|%-1.9p|", NULL); printf("|%-9.5p|", NULL); printf("|%-.p|", NULL);
//	printf("\n");
//	ft_printf("|%-1.p|", NULL); ft_printf("|%-1.1p|", NULL); ft_printf("|%-1.9p|", NULL); ft_printf("|%-9.5p|", NULL); printf("|%-.p|", NULL);
//	printf("\n"); 
//
//	printf("\n");
//	printf("|%-9.4p|", 1234); printf("|%-9p|", 1234); printf("|%-.10p|", 1234); printf("|%-9.2p|", 1234); printf("|%-p|", 1234);
//	printf("\n");
//	ft_printf("|%-9.4p|", 1234); ft_printf("|%-9p|", 1234); ft_printf("|%-.10p|", 1234); ft_printf("|%-9.2p|", 1234); printf("|%-p|", 1234);
//	printf("\n"); 
//
	// printf("\n");
	// printf("|%-9.p|", &j); printf("|%-9p|", &j); printf("|%-.10p|", &j); printf("|%-9.5p|", &j); printf("|%-p|", &j); printf("|%-15.20p|", &j);
	// printf("\n");
	// ft_printf("|%-9.p|", &j); ft_printf("|%-9p|", &j); ft_printf("|%-.10p|", &j); ft_printf("|%-9.5p|", &j); ft_printf("|%-p|", &j); ft_printf("|%-15.20p|", &j);
	// printf("\n"); 
	//printf("|%-15.3p|", 1234);
	// printf("\n"); 
	//ft_printf("|%-15.3p|", 1234);
	// printf("\n"); 
	//ft_printf("%d", -2147483648);
	// printf("%0.d,", l);
	// printf("\n");
	// ft_printf("%0.d,", l);
	// printf("\n");
	// printf("%2d,", 8);
	// printf("\n");
	//ft_printf("%p,", &j);
	//printf("%p,", &j);
	// printf("\n");
	// printf("%.*s,", 0, NULL);
	// printf("\n");
	// ft_printf("%.*s,", 0, NULL);
	// printf("\n");
	// printf("%*.*u, %*.*x, %*.*X,", a, b, l, a, b, l, a, b, l);
	// printf("\n");
	// ft_printf("%*.*u, %*.*x, %*.*X,", a, b, l, a, b, l, a, b, l);
	// printf("\n");
	//ft_printf("%x %x", 123243432, 678);
	//printf("%x %x", 123243432, 678);
	// int		a = -4;
	// int		b = 0;
	// char	c = 'a';
	// int		d = 2147483647;
	// int		e = -2147483648;
	// int		f = 42;
	// int		g = 25;
	// int		h = 4200;
	// int		i = 8;
	// int		j = -12;
	// int		k = 123456789;
	// int		l = 0;
	// int		m = -12345678;
	// char	*n = "abcdefghijklmnop";
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";

	// PRINT(" --- Return : %d\n", PRINT("Simple input test"));
	// PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	// PRINT(" --- Return : %d\n", PRINT("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d)); //T3
	// PRINT(" --- Return : %d\n", PRINT("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d)); //T4
	// PRINT(" --- Return : %d\n", PRINT("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d)); //T5
	// PRINT(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
	// PRINT(" --- Return : %d\n", PRINT("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
	// PRINT(" --- Return : %d\n", PRINT("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d)); //T8
	// PRINT(" --- Return : %d\n", PRINT("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d)); //T9
	// PRINT(" --- Return : %d\n", PRINT("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d)); //T10
	// PRINT(" --- Return : %d\n", PRINT("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d)); //T11
	// PRINT(" --- Return : %d\n", PRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
	// PRINT(" --- Return : %d\n", PRINT("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c, e, d)); //T13
	// PRINT(" --- Return : %d\n", PRINT("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d)); //T14
	// PRINT(" --- Return : %d\n", PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T15
	// PRINT(" --- Return : %d\n", PRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	// PRINT(" --- Return : %d\n", PRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
	// PRINT(" --- Return : %d\n", PRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
	// PRINT(" --- Return : %d\n", PRINT("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d)); //T19
	// PRINT(" --- Return : %d\n", PRINT("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c, e, d)); //T20
	// PRINT(" --- Return : %d\n", PRINT("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c, e, d)); //T21
	// PRINT(" --- Return : %d\n", PRINT("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c, e, d)); //T22
	// PRINT(" --- Return : %d\n", PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
	// PRINT(" --- Return : %d\n", PRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d)); //T24
	// PRINT(" --- Return : %d\n", PRINT("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c, e, d)); //T25
	// PRINT(" --- Return : %d\n", PRINT("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T26
	// PRINT(" --- Return : %d\n", PRINT("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c, e, d)); //T27
	// PRINT(" --- Return : %d\n", PRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T28
	// PRINT(" --- Return : %d\n", PRINT("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c, e, d)); //T29
	// PRINT(" --- Return : %d\n", PRINT("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d)); //T30
	// PRINT(" --- Return : %d\n", PRINT("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
	// PRINT(" --- Return : %d\n", PRINT("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d)); //T32
	// PRINT(" --- Return : %d\n", PRINT("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d)); //T33
	// while (a < 5) //T34-69
	// {
	// 	PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// 	PRINT(" --- Return : %d\n", PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// 	PRINT(" --- Return : %d\n", PRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// 	PRINT(" --- Return : %d\n", PRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// 	a++;
	// }
	// a = -2;
	// while(a < 5) //T70-177
	// {
	// 	b = -2;
	// 	while (b < 5)
	// 	{
	// 		PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		PRINT(" --- Return : %d\n", PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		PRINT(" --- Return : %d\n", PRINT("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		b++;
	// 	}
	// 	a++;
	// }
	// a = 19;
	// b = 14;
	// PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42)); //T178
	// PRINT(" --- Return : %d\n", PRINT("%12.12i, %12.12d", -42, 42)); //T179
	// PRINT(" --- Return : %d\n", PRINT("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T180
	// PRINT(" --- Return : %d\n", PRINT("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T181
	// PRINT(" --- Return : %d\n", PRINT("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T182
	// PRINT(" --- Return : %d\n", PRINT("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T183
	// PRINT(" --- Return : %d\n", PRINT("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T184
	// PRINT(" --- Return : %d\n", PRINT("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T185
	// PRINT(" --- Return : %d\n", PRINT("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r)); //T186
	// PRINT(" --- Return : %d\n", PRINT("%.s, %.s, %.s, %.s, %.s", n, o, p, q, r)); //T186
	// PRINT(" --- Return : %d\n", PRINT("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r)); //T186
	// a = -4;
	// while (a < 5) //T187-213
	// {
	// 	PRINT(" --- Return : %d\n", PRINT("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// 	PRINT(" --- Return : %d\n", PRINT("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// 	PRINT(" --- Return : %d\n", PRINT("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// 	a++;
	// }
	// a = -2;
	// while(a < 5) //T70-177
	// {
	// 	b = -2;
	// 	while (b < 5)
	// 	{
	// 		PRINT(" --- Return : %d\n", PRINT("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// 		PRINT(" --- Return : %d\n", PRINT("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// 		b++;
	// 	}
	// 	a++;
	// }

	// PRINT(" --- Return : %d\n", PRINT("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T214
	// a = -1;
	// while (a < 5) //T214-256
	// {
	// 	PRINT(" --- Return : %d\n", PRINT("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// 	PRINT(" --- Return : %d\n", PRINT("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// 	PRINT(" --- Return : %d\n", PRINT("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// 	PRINT(" --- Return : %d\n", PRINT("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// 	a++;
	// }
	// a = -1;
	// while(a < 5) //T257-346
	// {
	// 	b = -1;
	// 	while (b < 5)
	// 	{
	// 		PRINT(" --- Return : %d\n", PRINT("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// 		PRINT(" --- Return : %d\n", PRINT("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// 		PRINT(" --- Return : %d\n", PRINT("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// 		b++;
	// 	}
	// 	a++;
	// }
	// PRINT(" --- Return : %d\n", PRINT("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347
	// a = 8;
	// while (a < 12) //
	// {
	// 	PRINT(" --- Return : %d\n", PRINT("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// 	PRINT(" --- Return : %d\n", PRINT("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// 	a++;
	// }
	// a = f;
	// b = g;
	// PRINT(" --- Return : %d\n", PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
	// PRINT(" --- Return : %d\n", PRINT("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// PRINT(" --- Return : %d\n", PRINT("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// PRINT(" --- Return : %d\n", PRINT("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));

	// a = 12;
	// b = 18;
	// PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
	// PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c));
	// PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c));
	// PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255));
	// PRINT(" --- Return : %d\n", PRINT("%%, \t, \\, \", \', +"));
	// PRINT(" --- Return : %d\n", PRINT("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
	// PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	// PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	// PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	// PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
	// PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
	// PRINT(" --- Return : %d\n", PRINT("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	// PRINT(" --- Return : %d\n", PRINT("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	// // ^ Theoriquement un comportement indefini mais testé par la moulinette
    // PRINT(" --- Return : %d\n", PRINT("(null)"));
	// PRINT(" --- Return : %d\n", PRINT(""));
	// // printf("%.5%"); printf("%05%"); printf("%-5%"); printf("%5%"); printf("%3.5%"); printf("%-3.5%"); printf("%3%");
	// // printf("\n"); 
	// // ft_printf("%.5%"); ft_printf("%05%"); ft_printf("%-5%"); ft_printf("%5%"); ft_printf("%3.5%"); ft_printf("%-3.5%");  ft_printf("%3%"); 
	// printf("%5");
	// printf("\n");
	// int i = ft_printf("%432324");
	// printf("%d", i);
	//ft_printf("%432324");
	//ft_printf("%4f");
	// printf("%d", printf("%4|"));
	// printf("\n");
	// printf("%d", ft_printf("%4|"));
// 	int u = 5;
	
// 	printf("%d", printf("%-20yerwrewtre"));
// 	printf("\n");
// 	printf("%d", ft_printf("%-20ytrteter"));
// }

int main()
{
	int i;

	/**		BAxIC testx (NO-FLAGx)		**/
	i = ft_printf("%x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %x, ok ?\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %x, ok ?\n", 2147483647);
	ft_printf("ret : %d\n", i);

	/**		ONLY_PAxxING				**/
	i = ft_printf("%10x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%10x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%10x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %10x, ok ?\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %0x, ok ?\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %10x, ok ?\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %0x, ok ?\n", 2147483647);
	ft_printf("ret : %d\n", i);

	/**		PAxxING + PRECIxION			**/
	i = ft_printf("%50.30x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.30x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.2x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%3.2x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%2.3x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.30x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.0x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%.30x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", 0);
	ft_printf("ret : %d\n", i);

	i = ft_printf("%50.30x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.30x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.2x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%3.2x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%2.3x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.30x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.0x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%.30x\n", -2147483648);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", -2147483648);
	ft_printf("ret : %d\n", i);

	i = ft_printf("%50.30x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.30x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.2x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%3.2x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%2.3x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.30x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.0x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%.30x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", 2147483647);
	ft_printf("ret : %d\n", i);
}



