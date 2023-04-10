/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:01:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/04/10 20:46:32 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_free(t_philo *philo)
{
	free(philo->philo_data);
	sem_close(philo->forks);
	sem_close(philo->print);
	sem_close(philo->hold);
	sem_close(philo->stop);
}

int	main(int ac, char **av)
{
	t_philo			philo;

	if (ac != 5 && ac != 6)
		return (0);
	if (ft_init_philo(&philo, ac, av) == 1)
		return (0);
	ft_init_philo_data(&philo);
	philo_free(&philo);
}
