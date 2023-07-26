/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:47:38 by lzi-xian          #+#    #+#             */
<<<<<<< HEAD:bonus/philo_action_bonus.c
/*   Updated: 2023/07/26 16:30:49 by lzi-xian         ###   ########.fr       */
=======
/*   Updated: 2023/05/04 19:01:58 by lzi-xian         ###   ########.fr       */
>>>>>>> parent of c59d58f... Final update:bon/philo_action_bonus.c
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

<<<<<<< HEAD:bonus/philo_action_bonus.c
void	ft_odd_sleep(t_philo_data *data)
{
	if (data->x % 2 == 1)
	{
		print_time("is thinking\n", data);
		ft_usleep(data->vars->time_to_eat, data);
	}
}

=======
>>>>>>> parent of c59d58f... Final update:bon/philo_action_bonus.c
void	philo_fork(t_philo_data *data)
{
	sem_wait(data->vars->forks);
	print_time("has taken a fork\n", data);
	sem_wait(data->vars->forks);
	print_time("has taken a fork\n", data);
	print_time("is eating\n", data);
	sem_wait(data->vars->death);
<<<<<<< HEAD:bonus/philo_action_bonus.c
	data->eat = get_time();
	sem_post(data->vars->death);
	ft_usleep(data->vars->time_to_eat, data);
	sem_wait(data->vars->death);
=======
>>>>>>> parent of c59d58f... Final update:bon/philo_action_bonus.c
	if (data->eat_count != -1)
		data->eat_count++;
	data->eat = get_time();
	sem_post(data->vars->death);
	ft_usleep(data->vars->time_to_eat);
	sem_post(data->vars->forks);
	sem_post(data->vars->forks);
}

void	ft_odd_sleep(t_philo_data *data)
{
	if (data->x % 2 == 1)
	{
		print_time("is thinking\n", data);
		ft_usleep(data->vars->time_to_eat);
	}
}

void	*ft_check_death(void	*philo_data)
{
	t_philo_data	*data;

	data = (t_philo_data *)philo_data;
	while (1)
	{
		sem_wait(data->vars->death);
		if (get_time() - data->eat > data->vars->time_to_die)
		{
			print_time("died\n", data);
			sem_post(data->vars->stop);
			break ;
		}
		sem_post(data->vars->death);
		sem_wait(data->vars->death);
		if (data->eat_count != -1
			&& data->eat_count >= data->vars->need_eat_times)
		{
			sem_post(data->vars->stop);
			break ;
		}
		sem_post(data->vars->death);
	}
	return (NULL);
}

void	ft_philo_start(t_philo_data *data)
{
	pthread_t		stop;

	data->eat = get_time();
	pthread_create(&stop, NULL, &ft_check_death, data);
	ft_odd_sleep(data);
	while (1)
	{
		philo_fork(data);
		print_time("is sleeping\n", data);
		ft_usleep(data->vars->time_to_sleep, data);
		print_time("is thinking\n", data);
	}
	pthread_join(stop, NULL);
}
