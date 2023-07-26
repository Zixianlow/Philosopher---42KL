/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:05:37 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/07/26 20:20:02 by lzi-xian         ###   ########.fr       */
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
# include <signal.h>
# include <sys/time.h>
# include <sys/stat.h>

typedef struct s_philo
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				need_eat_times;
	long			time;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*stop;
	sem_t			*eat;
	sem_t			*death;
	struct timeval	timeval;
}	t_philo;

typedef struct s_philo_data
{
	int				x;
	int				eat_count;
	long			time;
	struct timeval	eat;
	pid_t			pid;
	t_philo			*vars;
}	t_philo_data;

void	ft_philo_start(t_philo_data *phil);
int		ft_init_philo(t_philo *philo, int ac, char **av);
int		ft_atoi(const char *str);
long	get_time(void);
void	print_time(char *s, t_philo_data *data);
void	ft_usleep(int i);
long	ft_time_diff(struct timeval time, long now);

#endif