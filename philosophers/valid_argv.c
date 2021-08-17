#include "philo.h"

int	ft_make_philo_param(t_top *top, char **argv)
{
	top->philo_count = ft_philo_atoi(argv[1]);
	top->death_time = ft_philo_atoi(argv[2]);
	top->eat_time = ft_philo_atoi(argv[3]);
	top->sleep_time = ft_philo_atoi(argv[4]);
	top->stop_eat_count = 0;
	top->somebady_ded = 0;
	top->full_philo_count = 0;
	top->i = 0;
	if (argv[5])
		top->stop_eat_count = ft_philo_atoi(argv[5]);
	if (top->philo_count < 1 || top->philo_count > 200
		|| top->death_time < 60 || top->eat_time < 60
		|| top->sleep_time < 60 || top->stop_eat_count < 0)
		return (-1);
	return (0);
}

int	ft_philo_atoi(const char *str)
{
	int	i;
	int	a;
	int	n;

	i = 0;
	a = 1;
	n = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		n *= 10;
		n += str[i] - '0';
		i++;
		if (i > 8)
			return (-1);
	}
	return (a * n);
}

int	ft_check_valid_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_philo_atoi(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
