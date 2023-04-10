/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:47:38 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/10 20:33:14 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork(t_philo_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->left_fork));
	print_time("has taken a fork\n", data);
	pthread_mutex_lock(data->right_fork);
	print_time("has taken a fork\n", data);
	pthread_mutex_lock(&(philo->eating));
	print_time("is eating\n", data);
	data->ate++;
	data->time = get_time();
	pthread_mutex_unlock(&(philo->eating));
	ft_usleep(philo->time_to_eat, data);
	pthread_mutex_unlock(data->right_fork);
	pthread_mutex_unlock(&(data->left_fork));
}

int	check_finish(t_philo *philo, int c)
{
	long	t;

	t = get_time();
	pthread_mutex_lock(&(philo->check));
	if (c == philo->number_of_philo)
	{
		philo->finish_time = t;
		pthread_mutex_unlock(&(philo->check));
		return (1);
	}
	pthread_mutex_unlock(&(philo->check));
	return (0);
}

int	check_done(t_philo *philo)
{
	int		i;
	int		c;

	c = 0;
	pthread_mutex_lock(&philo->stop);
	if (philo->dead == 1)
	{
		pthread_mutex_unlock(&philo->stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->stop);
	if (philo->need_eat_times == -1)
		return (0);
	pthread_mutex_lock(&(philo->eating));
	i = philo->number_of_philo - ((philo->number_of_philo + 1) % 2);
	if (philo->philo_data[i - 1].x == i)
		if (philo->philo_data[i - 1].ate >= philo->need_eat_times)
			c = philo->number_of_philo;
	pthread_mutex_unlock(&(philo->eating));
	if (check_finish(philo, c) == 1)
		return (1);
	return (0);
}

void	ft_odd_sleep(t_philo_data *data)
{
	if (data->x % 2 == 1)
	{
		print_time("is thinking\n", data);
		ft_usleep(data->vars->time_to_eat, data);
	}
}

void	*philo_start(void	*philo_data)
{
	t_philo_data	*data;

	data = (t_philo_data *)philo_data;
	if (data->vars->number_of_philo == 1)
	{
		print_time("has taken a fork\n", data);
		ft_usleep(data->vars->time_to_die + 10, data);
		return (NULL);
	}
	ft_odd_sleep(data);
	while (1)
	{
		if (check_done(data->vars))
			return (NULL);
		philo_fork(data, data->vars);
		if (check_done(data->vars))
			return (NULL);
		print_time("is sleeping\n", data);
		ft_usleep(data->vars->time_to_sleep, data);
		if (check_done(data->vars))
			return (NULL);
		print_time("is thinking\n", data);
		ft_usleep(data->vars->eat_sleep_gap, data);
	}
	return (NULL);
}
