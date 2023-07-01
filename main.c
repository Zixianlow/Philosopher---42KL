/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:01:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/07/01 14:17:20 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philo)
	{
		pthread_mutex_destroy(&philo->philo_data[i].left_fork);
		i++;
	}
	pthread_mutex_destroy(&philo->eating);
	pthread_mutex_destroy(&philo->printing);
	pthread_mutex_destroy(&philo->death);
	pthread_mutex_destroy(&philo->check);
	pthread_mutex_destroy(&philo->stop);
	free(philo->philo_data);
}

int	main(int ac, char **av)
{
	t_philo			philo;

	if (ac != 5 && ac != 6)
	{
		write(2, "Invalid number of arguments\n", 29);
		return (1);
	}
	if (ft_init_philo(&philo, ac, av) == 1)
	{
		write(2, "Non-numeric arguments\n", 23);
		return (1);
	}
	ft_init_philo_data(&philo);
	philo_free(&philo);
}
