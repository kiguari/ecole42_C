int ft_len_all_int_with_base(long int nb, int base)
{
	int i;
	
	i = 0;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		return (1);
	while(nb > 0)
	{
		nb /= base;
		i++;
	}
	return(i);
}