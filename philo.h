/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:05:37 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/09 21:13:50 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_data
{
	int					x;
	long				time;
	int					ate;
	struct s_philo		*vars;
	pthread_t			t;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
}	t_philo_data;

typedef struct s_philo
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					need_eat_times;
	int					dead;
	int					done;
	int					dead_count;
	int					unlucky;
	long				finish_time;
	long				a;
	long				b;
	long				time;
	struct s_philo_data	*philo_data;
	pthread_mutex_t		eating;
	pthread_mutex_t		printing;
	pthread_mutex_t		death;
	pthread_mutex_t		check;
	pthread_mutex_t		stop;
	struct timeval		timeval;
}	t_philo;

void	*philo_start(void	*phil);
void	ft_init_philo_data(t_philo *philo);
int		ft_init_philo(t_philo *philo, int ac, char **av);
int		ft_atoi(const char *str);
long	get_time(void);
void	print_time(char *s, t_philo_data *data);
void	ft_usleep(int i);
void	*ft_check_death(void *phi);

#endif