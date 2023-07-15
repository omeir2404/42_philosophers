#include "philo.h"

int	alloc(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (error("error", data));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (error("error", data));
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		return (error("error", data));
	return (0);
}

void philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].eat_cont = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int init_data(t_data *data, char **argv, int argc)
{
	data->philo_num = (int) ft_atoi(argv[1]);
	data->death_time = (long unsigned int) ft_atoi(argv[2]);
	data->eat_time = (long unsigned int) ft_atoi(argv[3]);
	data->sleep_time = (long unsigned int) ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_nb = (int) ft_atoi(argv[5]);
	else
		data->meals_nb = -1;
	if (data->philo_num <= 0 || data->philo_num > 200 || data->death_time < 0
		|| data->eat_time < 0 || data->sleep_time < 0)
		return (error("error", NULL));
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int	forks_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
	i = 1;
	while (i < data->philo_num)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

int	init(t_data *data, char **argv, int argc)
{
	if (init_data(data, argv, argc))
		return (1);
	if (alloc(data))
		return (1);
	if (forks_init(data))
		return (1);
	philo_init(data);
	return (0);
}
