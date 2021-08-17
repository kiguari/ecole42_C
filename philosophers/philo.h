#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

typedef struct s_top
{
	int				philo_count;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				stop_eat_count;
	int				somebady_ded;
	int				full_philo_count;
	int				now_time;
	int				i;
	struct timeval	start_time;
}	t_top;

typedef struct s_philos
{
	int				philo_num;
	int				eat_count;
	t_top			*top;
	struct timeval	last_time_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*message;
}	t_philos;

int		main(int argc, char **argv);
void	ft_philosof_init(t_philos *philos, t_top *top,
			pthread_mutex_t *forks, pthread_mutex_t *message);
void	*simulation(void *philosof);

void	ft_mutex_init(pthread_mutex_t *forks,
			pthread_mutex_t *message, t_top top);
void	ft_create_thread(t_philos *philos, t_top top);
void	ft_destroy_mutexs(t_top top,
			pthread_mutex_t *forks, pthread_mutex_t *message);
void	ft_detach(t_philos *philos, t_top *top);
void	ft_free(t_philos *philos, pthread_mutex_t *forks);

void	ft_philosophizm(t_philos *philos, t_top *top);
void	ft_philosof_eat(t_philos *philos, t_top *top);
void	thinking(t_philos *philos, t_top *top);
void	sleeping(t_philos *philos, t_top *top);

void	ft_sleep(struct timeval start_time, int time_sleep);
long	get_time(struct timeval time);

void	ft_message(int flag, t_philos *philos, t_top *top);
void	ft_ded_philos(t_philos *philos, t_top *top);
void	ft_wait_thread(t_philos *philos, t_top *top);

int		ft_check_valid_argv(char **argv);
int		ft_philo_atoi(const char *str);
int		ft_make_philo_param(t_top *top, char **argv);

#endif