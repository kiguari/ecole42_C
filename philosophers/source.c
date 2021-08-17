#include "philo.h"

void	ft_mutex_init(pthread_mutex_t *forks,
		pthread_mutex_t *message, t_top top)
{
	int	i;

	i = 0;
	while (i < top.philo_count)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	pthread_mutex_init(message, NULL);
}

void	ft_create_thread(t_philos *philos, t_top top)
{
	int	i;

	i = 0;
	while (i < top.philo_count)
	{
		pthread_create(&philos[i].thread, NULL,
			simulation, (void *)&philos[i]);
		i++;
	}
}

void	ft_destroy_mutexs(t_top top,
		pthread_mutex_t *forks, pthread_mutex_t *message)
{
	int	i;

	i = 0;
	while (i < top.philo_count)
	{
		pthread_mutex_destroy(&forks[i]);
		usleep(10);
		i++;
	}
	pthread_mutex_destroy(message);
}

void	ft_detach(t_philos *philos, t_top *top)
{
	int	i;

	i = 0;
	while (i < top->philo_count)
	{
		pthread_detach(philos[i].thread);
		i++;
	}
}

void	ft_free(t_philos *philos, pthread_mutex_t *forks)
{
	free(philos);
	free(forks);
}
