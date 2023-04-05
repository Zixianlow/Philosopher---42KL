/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:47:38 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/02/28 15:58:58 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_fork(t_philo_data *data, t_philo *philo)
{
	sem_wait(data->left);
	sem_wait(philo->forks);
	print_time("has taken a fork\n", data);
	sem_wait(*data->right);
	sem_wait(philo->forks);
	print_time("has taken a fork\n", data);
	print_time("is eating\n", data);
	data->time = get_time();
	ft_usleep(philo->time_to_eat, data);
	sem_post(philo->forks);
	sem_post(*data->right);
	sem_post(philo->forks);
	sem_post(data->left);
}

void	ft_odd_sleep(t_philo_data *data)
{
	if (data->x % 2 == 1)
	{
		print_time("is thinking\n", data);
		if (data->x == data->vars->number_of_philo)
			ft_usleep(3 * data->vars->time_to_eat - 10, data);
		else
			ft_usleep(data->vars->time_to_eat, data);
	}
}

int	ft_solve_for_one(t_philo *philo, t_philo_data *data)
{
	if (philo->number_of_philo == 1)
	{
		print_time("has taken a fork\n", data);
		usleep((philo->time_to_die + 10) * 1000);
		return (1);
	}
	return (0);
}

void	*philo_start(void	*philo_data)
{
	t_philo_data	*data;
	t_philo			*philo;

	data = (t_philo_data *)philo_data;
	philo = data->vars;
	if (ft_solve_for_one(philo, data))
		return (NULL);
	ft_odd_sleep(data);
	while (1)
	{
		if (philo->end > -1 && get_time() > (long)philo->end + philo->time)
			return (NULL);
		philo_fork(data, philo);
		if (philo->end > -1 && get_time() > (long)philo->end + philo->time)
			return (NULL);
		print_time("is sleeping\n", data);
		ft_usleep(philo->time_to_sleep, data);
		if (philo->end > -1 && get_time() > (long)philo->end + philo->time)
			return (NULL);
		print_time("is thinking\n", data);
		ft_usleep(philo->eat_sleep_gap, data);
	}
	return (NULL);
}
