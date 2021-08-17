#include "philo.h"

void	*simulation(void *philosof)
{
	t_top		*top;
	t_philos	*philos;

	philos = (t_philos *) philosof;
	top = philos->top;
	gettimeofday(&(top->start_time), NULL);
	gettimeofday(&(philos->last_time_meal), NULL);
	if (!(philos->philo_num % 2))
		ft_sleep(top->start_time, top->eat_time / 2);
	while (philos->top->somebady_ded == 0)
	{
		ft_philosof_eat(philos, top);
		if ((philos->eat_count == top->stop_eat_count)
			&& top->stop_eat_count > 0)
			return (NULL);
		ft_philosophizm(philos, top);
	}
	return (NULL);
}

void	ft_philosof_init(t_philos *philos, t_top *top,
		pthread_mutex_t *forks, pthread_mutex_t *message)
{
	int	i;

	i = 0;
	while (i < top->philo_count)
	{
		philos[i].philo_num = i + 1;
		philos[i].top = top;
		philos[i].right_fork = &forks[i];
		philos[i].left_fork = &forks[(i + 1) % top->philo_count];
		philos[i].message = message;
		philos[i].eat_count = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_top			top;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	t_philos		*philos;
	int				i;

	i = 0;
	if ((argc != 5 && argc != 6) || ft_check_valid_argv(argv) == -1
		|| ft_make_philo_param(&top, argv) == -1)
	{
		printf("error: wrong argc count or argv format\n");
		return (1);
	}
	philos = malloc(sizeof(t_philos) * top.philo_count);
	forks = malloc(sizeof(pthread_mutex_t) * top.philo_count);
	ft_philosof_init(philos, &top, forks, &message);
	ft_mutex_init(forks, &message, top);
	ft_create_thread(philos, top);
	usleep(60);
	ft_wait_thread(philos, &top);
	ft_destroy_mutexs(top, forks, &message);
	ft_free(philos, forks);
	return (0);
}
