#include "philo.h" 


int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else
		return (0);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	check_args(char **str, int argc)
{
	if (argc != 6 && argc != 5)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (ft_atoi(str[2]) <= 0 || ft_atoi(str[3]) <= 0
		|| ft_atoi(str[4]) <= 0 || ft_atoi(str[1]) < 1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (argc == 6)
	{
		if (ft_atoi(str[5]) <= 0)
		{
			write(1, "error\n", 6);
			return(0);
		}
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

// t_data *data(void)
// {
// 	static t_data data;

// 	return (&data);
// }

void	printphilids(int argc, t_data *data)
{
	int	i;

	i = 0;
	t_philo *temp;
	temp = data->philos;
	while(i < data->philo_num)
	{
		printf("%i ", temp[i].id);
		i++;
	}
}