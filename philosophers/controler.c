#include "philo.h"

void	ft_message(int flag, t_philos *philos, t_top *top)
{
	pthread_mutex_lock(philos->message);
	if (flag == 1 && top->somebady_ded == 0)
		printf("%ld %d has taken a fork\n", get_time(top->start_time),
			philos->philo_num);
	if (flag == 2 && top->somebady_ded == 0)
		printf("%ld %d is eating\n", get_time(top->start_time),
			philos->philo_num);
	if (flag == 3 && top->somebady_ded == 0)
		printf("%ld %d is sleeping\n", get_time(top->start_time),
			philos->philo_num);
	if (flag == 4 && top->somebady_ded == 0)
		printf("%ld %d is thinking\n", get_time(top->start_time),
			philos->philo_num);
	pthread_mutex_unlock(philos->message);
}

void	ft_ded_philos(t_philos *philos, t_top *top)
{
	top->somebady_ded = 1;
	pthread_mutex_lock(philos->message);
	printf("%ld %d is died\n", get_time(top->start_time),
		philos->philo_num);
	ft_detach(philos, top);
}

void	ft_wait_thread(t_philos *philos, t_top *top)
{
	int	now_time;

	while (top->i < top->philo_count)
	{
		now_time = (int)get_time(philos[top->i].last_time_meal);
		if ((now_time > philos->top->death_time + 2) || top->somebady_ded)
		{
			ft_ded_philos(philos, top);
			break ;
		}
		if ((philos[top->i].eat_count == top->stop_eat_count)
			&& top->stop_eat_count > 0)
		{
			philos[top->i].eat_count = 0;
			top->full_philo_count++;
			if (top->full_philo_count == top->philo_count)
			{
				ft_detach(philos, top);
				break ;
			}
		}
		top->i++;
		if (top->i == top->philo_count)
			top->i = 0;
	}
}
