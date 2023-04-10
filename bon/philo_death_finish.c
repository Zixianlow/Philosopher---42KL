/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death_finish.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:56:24 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/02/23 17:56:19 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_die(t_philo *philo)
{
	int	n;

	n = ((philo->number_of_philo % 2) + 2) * philo->time_to_eat;
	if (n > philo->time_to_die)
		philo->die = philo->time_to_die;
	else
		philo->die = -1;
}

void	ft_finish(t_philo *philo)
{
	int	e;
	int	n;

	e = philo->need_eat_times;
	n = e / 2;
	if (philo->number_of_philo % 2 == 1)
		philo->finish = ((e * 3) - n) * philo->time_to_eat + philo->time_to_eat;
	else
		philo->finish = (e * 2) * philo->time_to_eat;
}

void	ft_death_and_finish(t_philo *philo)
{
	ft_die(philo);
	if (philo->need_eat_times == -1)
		philo->finish = -1;
	else
		ft_finish(philo);
	if (philo->finish > -1)
	{
		if (philo->die > -1 && philo->die > philo->finish)
			philo->die = -1;
		else if (philo->die > -1 && philo->die < philo->finish)
			philo->finish = -1;
	}
	if (philo->die == -1)
		philo->end = philo->finish;
	else if (philo->finish == -1)
		philo->end = philo->die;
	else
		philo->end = -1;
}
