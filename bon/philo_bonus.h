/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:05:37 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/10 20:38:35 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h>

typedef struct s_philo_data
{
	int					x;
	long				time;
	struct s_philo		*vars;
	pthread_t			t;
}	t_philo_data;

typedef struct s_philo
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					need_eat_times;
	int					eat_sleep_gap;
	int					dead;
	int					dead_count;
	long				a;
	long				b;
	long				time;
	struct s_philo_data	*philo_data;
	sem_t				*forks;
	sem_t				*print;
	sem_t				*stop;
	sem_t				*hold;
	struct timeval		timeval;
}	t_philo;

void	*philo_start(void	*phil);
void	ft_init_philo_data(t_philo *philo);
int		ft_init_philo(t_philo *philo, int ac, char **av);
int		ft_atoi(const char *str);
long	get_time(void);
void	print_time(char *s, t_philo_data *data);
void	ft_usleep(int i, t_philo_data *data);
void	ft_death_and_finish(t_philo *philo);

#endif