#include "philo.h" 


void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

int	case_one(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (error("thread error", data));
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_usleep(0);
	ft_exit(data);
	return (0);
}




int main(int argc, char **argv)
{
	t_data	data;


	if (!check_args(argv, argc))
		return(1);
	// printphilids(argc, &data);

	init(&data, argv, argc);
	if (data.philo_num == 1)
		return (case_one(&data));
	if (thread_init(&data))
		return (1);
	ft_exit(&data);
	return (0);
}




// int	case_one(t_data *data)
// {
// 	data->start_time = get_time();
// 	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
// 		return (error("thread error", data));
// 	pthread_detach(data->tid[0]);
// 	while (data->dead == 0)
// 		ft_usleep(0);
// 	ft_exit(data);
// 	return (0);
// }

// void	clear_data(t_data	*data)
// {
// 	if (data->tid)
// 		free(data->tid);
// 	if (data->forks)
// 		free(data->forks);
// 	if (data->philos)
// 		free(data->philos);
// }

// int	error(char *str, t_data *data)
// {
// 	printf("%s\n", str);
// 	if (data)
// 		ft_exit(data);
// 	return (1);
// }

// int	main(int argc, char **argv)
// {
// 	t_data	data;

// 	if (argc < 5 || argc > 6)
// 		return (1);
// 	if (input_checker(argv))
// 		return (1);
// 	if (init(&data, argv, argc))
// 		return (1);
// 	if (data.philo_num == 1)
// 		return (case_one(&data));
// 	if (thread_init(&data))
// 		return (1);
// 	ft_exit(&data);
// 	return (0);
// }
