/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:47:38 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/07/27 16:03:05 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_odd_sleep(t_philo_data *data)
{
	if (data->vars->number_of_philo == 1)
		return ;
	if (data->x % 2 == 1)
	{
		print_time("is thinking\n", data);
		ft_usleep(data->vars->time_to_eat);
	}
}

void	philo_fork(t_philo_data *data)
{
	sem_wait(data->vars->forks);
	print_time("has taken a fork\n", data);
	sem_wait(data->vars->forks);
	print_time("has taken a fork\n", data);
	print_time("is eating\n", data);
	if (data->eat_count != -1)
	{
		data->eat_count++;
		if (data->eat_count == data->vars->need_eat_times)
			sem_post(data->vars->eat);
	}
	sem_wait(data->vars->death);
	gettimeofday(&(data->eat), NULL);
	sem_post(data->vars->death);
	ft_usleep(data->vars->time_to_eat);
	sem_post(data->vars->forks);
	sem_post(data->vars->forks);
}

void	*ft_check_death(void	*philo_data)
{
	t_philo_data	*data;

	data = (t_philo_data *)philo_data;
	while (1)
	{
		sem_wait(data->vars->death);
		if (ft_time_diff(data->eat, get_time()) > data->vars->time_to_die)
		{
			print_time("died\n", data);
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

	ft_odd_sleep(data);
	pthread_create(&stop, NULL, &ft_check_death, data);
	pthread_detach(stop);
	while (1)
	{
		philo_fork(data);
		print_time("is sleeping\n", data);
		ft_usleep(data->vars->time_to_sleep);
		print_time("is thinking\n", data);
	}
}
