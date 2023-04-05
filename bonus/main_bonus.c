/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:01:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/02/28 16:02:26 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_free(t_philo *philo)
{
	free(philo->philo_data);
	sem_close(philo->forks);
}

void	ft_print_died(t_philo *philo)
{
	int	n;

	n = 0;
	if (philo->end == -1)
		return ;
	if (philo->end == philo->finish)
		return ;
	if (philo->time_to_die < philo->time_to_eat)
		n = 1;
	else if (philo->time_to_die < philo->time_to_eat * 2)
		n = 2;
	else if (philo->time_to_die > philo->time_to_eat * 2)
		n = philo->number_of_philo;
	if (philo->number_of_philo == 1)
		n = 1;
	printf("%d	%d died", philo->end, n);
}

int	main(int ac, char **av)
{
	t_philo			philo;

	if (ac != 5 && ac != 6)
		return (0);
	if (ft_init_philo(&philo, ac, av) == 1)
		return (0);
	ft_init_philo_data(&philo);
	ft_print_died(&philo);
	philo_free(&philo);
}
