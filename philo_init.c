/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:28:23 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/02/16 20:06:34 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_and_join_thread(t_philo *philo)
{
	int				i;
	t_philo_data	*data;

	i = 0;
	data = philo->philo_data;
	while (i < philo->number_of_philo)
	{
		pthread_create(&data[i].t, NULL, &philo_start, &(philo->philo_data[i]));
		i++;
	}
	i = 0;
	while (i < philo->number_of_philo)
	{
		pthread_join(data[i].t, NULL);
		i++;
	}
}

void	ft_init_philo_data(t_philo *philo)
{
	int				i;
	t_philo_data	*data;

	i = 0;
	data = philo->philo_data;
	while (i < philo->number_of_philo)
	{
		data[i].x = i + 1;
		data[i].time = philo->time;
		data[i].ate = 0;
		pthread_mutex_init(&(data[i].left_fork), NULL);
		if (i > 0)
		{
			data[i].right_fork = &data[i - 1].left_fork;
		}
		if (i + 1 == philo->number_of_philo && i + 1 > 1)
		{
			data[0].right_fork = &data[i].left_fork;
		}
		data[i].vars = philo;
		i++;
	}
	ft_create_and_join_thread(philo);
}

void	ft_init_philo_cont(t_philo *philo)
{
	if (philo->time_to_eat > philo->time_to_sleep)
		philo->eat_sleep_gap = philo->time_to_eat - philo->time_to_sleep;
	else
		philo->eat_sleep_gap = 0;
	philo->dead = 0;
	philo->finish_time = 0;
	philo->dead_count = 0;
	gettimeofday(&(philo->timeval), NULL);
	philo->a = philo->timeval.tv_sec;
	philo->b = philo->timeval.tv_usec;
	philo->time = (philo->a * 1000) + (philo->b / 1000);
	pthread_mutex_init(&(philo->eating), NULL);
	pthread_mutex_init(&(philo->printing), NULL);
	pthread_mutex_init(&(philo->death), NULL);
	pthread_mutex_init(&(philo->check), NULL);
	pthread_mutex_init(&(philo->stop), NULL);
	philo->philo_data = malloc(sizeof(t_philo_data) * philo->number_of_philo);
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
