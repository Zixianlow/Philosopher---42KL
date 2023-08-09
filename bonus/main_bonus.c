/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:01:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/07/27 14:57:18 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_free(t_philo *philo)
{
	int	i;

	i = -1;
	kill(0, SIGINT);
	sem_close(philo->forks);
	sem_close(philo->print);
	sem_close(philo->death);
	sem_close(philo->stop);
}

void	ft_full_eat(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->need_eat_times != -1)
	{
		if (fork() != 0)
			return ;
		while (++i < philo->number_of_philo)
			sem_wait(philo->eat);
		waitpid(-1, NULL, 0);
		kill(0, SIGINT);
	}
}

void	ft_create_philo(t_philo *philo)
{
	int				i;
	t_philo_data	data;

	i = 0;
	data.vars = philo;
	if (philo->need_eat_times != -1)
		data.eat_count = 0;
	else
		data.eat_count = -1;
	philo->time = get_time();
	while (i < philo->number_of_philo)
	{
		data.x = i + 1;
		data.time = philo->time;
		gettimeofday(&(data.eat), NULL);
		data.pid = fork();
		if (data.pid == 0)
		{
			ft_philo_start(&data);
			exit(0);
		}
		i++;
	}
	ft_full_eat(philo);
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
	sem_wait(philo->stop);
	ft_create_philo(philo);
	sem_wait(philo->stop);
	philo_free(philo);
}
