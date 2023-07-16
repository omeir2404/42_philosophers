/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:27:36 by oharoon           #+#    #+#             */
/*   Updated: 2023/07/16 17:34:56 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * (long unsigned int)1000) + (tv.tv_usec / 1000));
}

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else
		return (0);
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
			return (0);
		}
	}
	return (1);
}

long	ft_atoi(const char *str)
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

void	printphilids(int argc, t_data *data)
{
	int		i;
	t_philo	*temp;

	i = 0;
	temp = data->philos;
	while (i < data->philo_num)
	{
		printf("%i ", temp[i].id);
		i++;
	}
}
