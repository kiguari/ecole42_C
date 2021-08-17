#include "libft.h"
#include <stdio.h>
#include "ft_strlen.c"
#include "ft_itoa.c"
#include "ft_strtrim.c"
#include "ft_strdup.c"
#include "ft_substr.c"
//#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_strjoin.c"
#include "ft_memcpy.c"
#include "ft_split.c"
#include "ft_memcmp.c"

int	main()
{
//	char src[] = "  -9223372036854775810534545425454524 ";
//	char *src2 = "";
//	unsigned long src = 0xdeadbeef;
	char **split;
//	char	*buff1;
//	char	buff2[22];
//	unsigned long dest1;
//	unsigned long dest2;
//	char *r = ft_memccpy(buff1, src, 'm', 22);
//	printf("%s\n", r);
//	char *data = "ejfinOIUUDo872^^&I^gf^GgT^5fu%f%YFj";
//	buff1 = strdup(((void*)0));
//	ft_memcpy(buff2, src, 22);
//	long a = −908;

//	int a=12345, b=12345;
//	printf("stand %d\n", atoi(src));
//	printf("moe   %d\n", (int)a);
//	printf("%lu \n", sizeof(buff1));
//	printf("stand %s\n", ft_strjoin("1", "2"));
//	printf("moe   %lu\n", ft_strlen(buff2));
//	printf("%s\n", buff2);
//
	int	i = 0;
	split = ft_split("          ", ' ');
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}
