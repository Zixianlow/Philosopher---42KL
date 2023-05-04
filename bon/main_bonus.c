/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:01:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/04 19:04:55 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->number_of_philo)
		kill(philo->philo_data[i].pid, SIGKILL);
	sem_close(philo->forks);
	sem_close(philo->print);
	sem_close(philo->death);
	sem_close(philo->stop);
	free(philo->philo_data);
}

void	ft_create_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philo)
	{
		philo->philo_data[i].time = get_time();
		philo->philo_data[i].pid = fork();
		if (philo->philo_data[i].pid == 0)
		{
			ft_philo_start(&philo->philo_data[i]);
			exit(0);
		}
		i++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	t_philo			*philo;

	if (ac != 5 && ac != 6)
		return (0);
	philo = malloc(sizeof(t_philo));
	if (ft_init_philo(philo, ac, av))
	{
		free(philo);
		return (0);
	}
	ft_init_philo_data(philo);
	sem_wait(philo->stop);
	ft_create_philo(philo);
	sem_wait(philo->stop);
	philo_free(philo);
}
