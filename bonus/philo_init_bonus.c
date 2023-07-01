/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:28:23 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/05/19 20:55:33 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_philo_cont(t_philo *philo)
{
	sem_unlink("forks");
	philo->forks = sem_open("forks", O_CREAT, 0644, philo->number_of_philo);
	sem_unlink("print");
	philo->print = sem_open("print", O_CREAT, 0644, 1);
	sem_unlink("death");
	philo->death = sem_open("death", O_CREAT, 0644, 1);
	sem_unlink("stop");
	philo->stop = sem_open("stop", O_CREAT, 0644, 1);
	sem_unlink("eat");
	philo->eat = sem_open("eat", O_CREAT, 0644, 0);
}

int	ft_check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_init_philo(t_philo *philo, int ac, char **av)
{
	if (ft_check_num(ac, av) == 0)
		return (1);
	philo->number_of_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->need_eat_times = ft_atoi(av[5]);
	else
		philo->need_eat_times = -1;
	ft_init_philo_cont(philo);
	return (0);
}
