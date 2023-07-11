#ifndef PHILO_H

#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_philo
{
	struct s_data	*data;
	int             id;
	int             eat_cont;
	int             status;
	int				eating;
	unsigned int	time_to_die;
	pthread_mutex_t	lock;
	bool			fork;
	pthread_mutex_t	*mutex_fork;
	pthread_t		pthread;
	struct s_philo			*next;
}					t_philo;

typedef struct s_data
{
	pthread_t       *tid;
	t_philo			*begin;
	int             philo_num;
	int             meals_nb;
	int             dead;
	int             finished;
	t_philo         *philos;
	unsigned int       death_time;
	unsigned int       eat_time;
	unsigned int       sleep_time;
	unsigned int       start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
} t_data;

void	*routine(void *data_pointer);
int		init(char **argv,t_data *data, int argc);
t_philo	*create_philo(int id);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
// void	philo_init(int num, t_philo **philos);
t_data *data(t_data *data);
t_philo	*philos(void);
int	check_args(char **str, int argc);
int	ft_atoi(const char *str);
t_philo	*ft_lstlast(t_philo *lst);
void	philo_init(t_data *data);


void	printphilids(int argc, t_data *data);

#endif