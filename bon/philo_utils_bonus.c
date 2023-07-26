/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:03:59 by lzi-xian          #+#    #+#             */
<<<<<<< HEAD:bonus/philo_utils_bonus.c
/*   Updated: 2023/07/26 16:29:56 by lzi-xian         ###   ########.fr       */
=======
/*   Updated: 2023/05/04 19:01:59 by lzi-xian         ###   ########.fr       */
>>>>>>> parent of c59d58f... Final update:bon/philo_utils_bonus.c
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			r = r * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (r * s);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&(time), NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_time(char *s, t_philo_data *data)
{
	long			t;

	sem_wait(data->vars->death);
	t = get_time();
<<<<<<< HEAD:bonus/philo_utils_bonus.c
	sem_post(data->vars->death);
	sem_wait(data->vars->print);
=======
	// sem_wait(data->vars->print);
>>>>>>> parent of c59d58f... Final update:bon/philo_utils_bonus.c
	printf("%ld	%d %s", t - data->time, data->x, s);
	// sem_post(data->vars->print);
}

void	ft_usleep(int i)
{
	long	t;

	t = get_time();
	while (get_time() - t < i)
		usleep(500);
}
