#include "philo.h"

long	get_time(struct timeval time)
{
	struct timeval	now;
	long			time_in_ms;

	gettimeofday(&now, NULL);
	time_in_ms = (now.tv_sec - time.tv_sec) * 1000
		+ (now.tv_usec - time.tv_usec) / 1000;
	return (time_in_ms);
}

void	ft_sleep(struct timeval start_time, int time_sleep)
{
	long	wait;

	wait = get_time(start_time) + time_sleep;
	while (get_time(start_time) < wait)
		usleep(500);
}
