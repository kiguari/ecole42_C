#include <unistd.h>

int			ft_putstr_with_counter(char *str)
{
	int		i;
	
	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}
