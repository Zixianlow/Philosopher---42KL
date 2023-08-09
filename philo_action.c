/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:47:38 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/09 21:06:52 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_done(t_philo_data *data)
{
	pthread_mutex_lock(&data->vars->stop);
	if (data->vars->dead == 1)
	{
		pthread_mutex_unlock(&data->vars->stop);
		return (1);
	}
	pthread_mutex_unlock(&data->vars->stop);
	if (data->vars->need_eat_times == -1)
		return (0);
	pthread_mutex_lock(&data->vars->check);
	if (data->vars->done == data->vars->number_of_philo)
	{
		pthread_mutex_unlock(&data->vars->check);
		return (1);
	}
	pthread_mutex_unlock(&data->vars->check);
	return (0);
}

void	philo_fork(t_philo_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->left_fork));
	if (check_done(data))
		return ;
	print_time("has taken a fork\n", data);
	pthread_mutex_lock(data->right_fork);
	if (check_done(data))
		return ;
	print_time("has taken a fork\n", data);
	pthread_mutex_lock(&(philo->eating));
	print_time("is eating\n", data);
	data->ate++;
	pthread_mutex_lock(&philo->check);
	if (data->vars->need_eat_times != -1
		&& data->ate == data->vars->need_eat_times)
		data->vars->done++;
	pthread_mutex_unlock(&philo->check);
	data->time = get_time();
	pthread_mutex_unlock(&(philo->eating));
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(data->right_fork);
	pthread_mutex_unlock(&(data->left_fork));
}

void	ft_odd_sleep(t_philo_data *data)
{
	if (data->x % 2 == 1)
	{
		print_time("is thinking\n", data);
		ft_usleep(data->vars->time_to_eat);
	}
}

void	*philo_start(void	*philo_data)
{
	t_philo_data	*data;

	data = (t_philo_data *)philo_data;
	if (data->vars->number_of_philo == 1)
	{
		print_time("has taken a fork\n", data);
		ft_usleep(data->vars->time_to_die + 10);
		return (NULL);
	}
	ft_odd_sleep(data);
	while (1)
	{
		if (check_done(data))
			return (NULL);
		philo_fork(data, data->vars);
		if (check_done(data))
			return (NULL);
		print_time("is sleeping\n", data);
		ft_usleep(data->vars->time_to_sleep);
		if (check_done(data))
			return (NULL);
		print_time("is thinking\n", data);
	}
	return (NULL);
}
