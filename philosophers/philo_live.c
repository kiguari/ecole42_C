#include "philo.h"

void	sleeping(t_philos *philos, t_top *top)
{
	ft_message(3, philos, top);
	ft_sleep(top->start_time, top->sleep_time);
}

void	thinking(t_philos *philos, t_top *top)
{
	ft_message(4, philos, top);
}

void	ft_philosof_eat(t_philos *philos, t_top *top)
{
	pthread_mutex_lock(philos->right_fork);
	ft_message(1, philos, top);
	if (philos->top->philo_count == 1)
	{
		ft_sleep(top->start_time, top->death_time);
		philos->top->somebady_ded = 1;
		return ;
	}
	pthread_mutex_lock(philos->left_fork);
	ft_message(1, philos, top);
	ft_message(2, philos, top);
	gettimeofday(&(philos->last_time_meal), NULL);
	ft_sleep(top->start_time, top->eat_time);
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
	philos->eat_count += 1;
}

void	ft_philosophizm(t_philos *philos, t_top *top)
{
	sleeping(philos, top);
	thinking(philos, top);
}
