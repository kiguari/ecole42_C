#include <unistd.h>

int ft_len(long int nb)
{
	int i = 0;
	if (nb == 0)
		return (1);
	while(nb > 0)
	{
		nb /= 10;
		i++;
	}
	return(i);
}

int ft_putnbr_with_counter(long int d)
{
	char c;
	int i;
	
	i = 0;
	if (d < 0)
	{
		d *= -1;
		// i++;					//if need printf and count sign;
		// write(1, "-", 1);
	}
	if (d != 0)
	{
		if(d/10)
			ft_putnbr_with_counter(d/10);
		c = '0' + (d % 10);
		write(1, &c, 1);
	}
	else
		write(1, "0", 1);
	i += ft_len(d);
	return (i);
}
