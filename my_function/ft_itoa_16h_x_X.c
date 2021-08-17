#include <stdlib.h>

static void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	void		*a;

	a = dst;
	if (!n || (char *)dst == (char *)src)
		return (dst);
	while (n--)
	{
		*((char *)dst) = *((char *)src);
		dst++;
		src++;
	}
	return (a);
}

char			*ft_itoa_16h_x_X(int n, char *point)
{
	char		*str;
	int			len;
	size_t		b;
	char		set[17];

	b = (unsigned int)n;
	len = ft_len2(b);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (*point == 'X')
		ft_memcpy(set, "0123456789ABCDEF", 17);
	if (*point == 'x')
		ft_memcpy(set, "0123456789abcdef", 17);
	str[len--] = '\0';
	if (b == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (b > 0)
	{
		str[len--] = set[b % 16];
		b = b / 16;
	}
	return (str);
}