/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:03:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/02/22 21:02:58 by lzi-xian         ###   ########.fr       */
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
	long			t;

	gettimeofday(&(time), NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t);
}

void	print_time(char *s, t_philo_data *data)
{
	struct timeval	time;
	t_philo			*philo;
	long			t;

	philo = data->vars;
	gettimeofday(&(time), NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (philo->end > -1 && get_time() < (long)philo->end + philo->time)
	{
		sem_wait(data->vars->printing);
		printf("%ld	%d %s", t - philo->time, data->x, s);
		sem_post(data->vars->printing);
	}
	else if (philo->finish == -1 && philo->die == -1)
	{
		sem_wait(data->vars->printing);
		printf("%ld	%d %s", t - philo->time, data->x, s);
		sem_post(data->vars->printing);
	}
}

void	ft_usleep(int i, t_philo_data *data)
{
	long			t;
	t_philo			*philo;

	philo = data->vars;
	t = get_time();
	while (get_time() - t < i)
	{
		if (philo->end > -1 && get_time() > (long)philo->end + philo->time)
			return ;
		usleep(100);
	}
}
