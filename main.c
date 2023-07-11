#include "philo.h" 



// void	*routine(void *data_pointer)
// {
	
// }


int	alloc(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		return (1);
	return (0);
}

// void	ft_lstadd_back(t_philo **lst, t_philo *new)
// {
// 	t_philo	*temp;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	temp = ft_lstlast(*lst);
// 	temp->next = new;
// }


// t_philo	*create_philo(int id)
// {
// 	t_philo	*philo;

// 	philo = malloc(sizeof(t_philo));
// 	if (!(philo))
// 		return (NULL);
// 	philo->id = id;
// 	philo->next = NULL;
// 	return(philo);
// }


void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	alloc(data);
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


// void	philo_init(int num)
// {
// 	int	i;


// 	t_philo	*temp = NULL;
// 	i = 0;
// 	// data()->philos[0] = create_philo(1);
// 	while(i < num)
// 	{
// 		ft_lstadd_back(data()->philos, create_philo(i+1));
// 		i++;
// 	}
// 	temp = &data()->philos[0];
// 	while (data()->philos->next)
// 		data()->philos = data()->philos->next;
// 	data()->philos[0].next = temp;
// 	data()->philos = data()->philos->next;
// 	data()->begin = &data()->philos;
// }

int		init(char **argv,t_data *data, int argc)
{
	data->philo_num = ft_atoi(argv[1]);
	data->death_time = (unsigned int) ft_atoi(argv[2]);
	data->eat_time = (unsigned int) ft_atoi(argv[3]);
	data->sleep_time = (unsigned int) ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_nb = (unsigned int) ft_atoi(argv[5]);
	else
		data->meals_nb = -1;
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	philo_init(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;
	// t_philo *philos;

	// philos = NULL;
	if (!check_args(argv, argc))
		return(1);
	init(argv, &data, argc);

	printphilids(argc, &data);
}