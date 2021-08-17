#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		ft_len(long int n)
{
	long int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(long long int n)
{
	char		*str;
	int			len;
	long		b;
   
	b = (long)n;
	len = ft_len(b);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (b == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (b < 0)
	{
		str[0] = '-';
		b = b * -1;
	}
	while (b > 0)
	{
		str[--len] = 48 + (b % 10);
		b = b / 10;
	}
	return (str);
}

int main ()
{
    FILE *file;

    long long int a;
    long long int d;
    long long int c;
    int fd;
    int test;
    char *str;
    int test_2;
   
    file = fopen("input.txt", "r");
    if(!file)
        return(0);
    test = fscanf(file, "%lld %lld", &a, &d);
    if(!test)
        return(0);
    c = a + d;
    fd = open("output.txt", O_CREAT | O_WRONLY, 0755);
    if(!fd)
        return(0);
    str = ft_itoa(c);
    test_2 = ft_strlen(str);
    if (write(fd, str, test_2) == -1)
        return(0);
    // printf("%zu", c);
    free(str);
    return(0);
}
