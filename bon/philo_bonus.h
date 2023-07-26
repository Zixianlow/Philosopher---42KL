/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:05:37 by lzi-xian          #+#    #+#             */
<<<<<<< HEAD:bonus/philo_bonus.h
/*   Updated: 2023/07/26 16:30:17 by lzi-xian         ###   ########.fr       */
=======
/*   Updated: 2023/05/04 19:00:02 by lzi-xian         ###   ########.fr       */
>>>>>>> parent of c59d58f... Final update:bon/philo_bonus.h
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

typedef struct s_philo_data
{
	int					x;
	int					eat_count;
	long				time;
	long				eat;
	pid_t				pid;
	struct s_philo		*vars;
}	t_philo_data;

typedef struct s_philo
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					need_eat_times;
	long				time;
	struct s_philo_data	*philo_data;
	sem_t				*forks;
	sem_t				*print;
	sem_t				*stop;
	sem_t				*death;
	struct timeval		timeval;
}	t_philo;

void	ft_philo_start(t_philo_data *phil);
void	ft_init_philo_data(t_philo *philo);
int		ft_init_philo(t_philo *philo, int ac, char **av);
int		ft_atoi(const char *str);
long	get_time(void);
void	print_time(char *s, t_philo_data *data);
<<<<<<< HEAD:bonus/philo_bonus.h
void	ft_usleep(int i, t_philo_data *data);
=======
void	ft_usleep(int i);
void	ft_death_and_finish(t_philo *philo);
>>>>>>> parent of c59d58f... Final update:bon/philo_bonus.h

#endif