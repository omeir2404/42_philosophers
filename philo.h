/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:27:07 by oharoon           #+#    #+#             */
/*   Updated: 2023/07/16 17:30:43 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			t1;
	int					id;
	int					eat_cont;
	int					status;
	int					eating;
	long unsigned int	time_to_die;
	pthread_mutex_t		lock;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t			*tid;
	t_philo				*begin;
	int					philo_num;
	int					meals_nb;
	int					dead;
	int					finished;
	t_philo				*philos;
	unsigned int		death_time;
	unsigned int		eat_time;
	unsigned int		sleep_time;
	unsigned int		start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		write;
}						t_data;

void			*routine(void *data_pointer);
int				init_data(t_data *data, char **argv, int argc);
t_philo			*create_philo(int id);
void			ft_lstadd_back(t_philo **lst, t_philo *new);
t_data			*data(t_data *data);
t_philo			*philos(void);
int				check_args(char **str, int argc);
long			ft_atoi(const char *str);
t_philo			*ft_lstlast(t_philo *lst);
void			philo_init(t_data *data);
int				init(t_data *data, char **argv, int argc);
int				forks_init(t_data *data);
void			printphilids(int argc, t_data *data);
void			ft_clean(t_data *data);
void			clear_data(t_data	*data);
int				error(char *str, t_data *data);
unsigned int	get_time(void);
int				ft_usleep(long unsigned int time);
int				ft_strcmp(char *s1, char *s2);

void			ft_exit(t_data *data);

void			messages(char *str, t_philo *philo);
void			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);
void			eat(t_philo *philo);
void			*superviser(void *philo_pointer);
void			*monitor(void *data_pointer);
void			*routine(void *philo_pointer);
int				thread_init(t_data *data);

#endif
