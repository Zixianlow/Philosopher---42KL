/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:13:13 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/09 21:24:16 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->check);
	if (philo->done == philo->need_eat_times)
	{
		pthread_mutex_unlock(&philo->check);
		return (1);
	}
	pthread_mutex_unlock(&philo->check);
	pthread_mutex_lock(&philo->stop);
	if (philo->dead == 1)
	{
		pthread_mutex_unlock(&philo->stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->stop);
	return (0);
}

void	ft_set_dead(t_philo	*philo, int i)
{
	pthread_mutex_lock(&(philo->eating));
	if (get_time() - philo->philo_data[i].time > philo->time_to_die)
	{
		pthread_mutex_lock(&philo->stop);
		if (philo->dead == 0)
			print_time(" died\n", &philo->philo_data[i]);
		philo->dead++;
		pthread_mutex_unlock(&philo->stop);
	}
	pthread_mutex_unlock(&(philo->eating));
}

void	*ft_check_death(void *phi)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)phi;
	while (1)
	{
		if (ft_check_end(philo))
			return (NULL);
		i = 0;
		while (i < philo->number_of_philo)
		{
			if (ft_check_end(philo))
				return (NULL);
			ft_set_dead(philo, i);
			i++;
		}
		usleep(1000);
	}
}
