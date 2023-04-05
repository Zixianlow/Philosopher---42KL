/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:03:59 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/02/22 17:48:36 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	long			t;

	gettimeofday(&(time), NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_lock(&(data->vars->printing));
	pthread_mutex_lock(&(data->vars->check));
	if (data->vars->finish_time)
	{
		if (data->vars->dead == 0 && t < data->vars->finish_time)
			printf("%ld	%d %s", t - data->vars->time, data->x, s);
	}
	else
	{
		pthread_mutex_lock(&data->vars->stop);
		if (data->vars->dead == 0)
			printf("%ld	%d %s", t - data->vars->time, data->x, s);
		pthread_mutex_unlock(&data->vars->stop);
	}
	pthread_mutex_unlock(&(data->vars->printing));
	pthread_mutex_unlock(&(data->vars->check));
}

int	check_dead(t_philo_data *data)
{
	long	t;

	t = get_time();
	if (t - data->time > data->vars->time_to_die)
	{
		pthread_mutex_lock(&data->vars->death);
		if (data->vars->dead_count == 0)
			print_time("died\n", data);
		pthread_mutex_lock(&data->vars->stop);
		data->vars->dead = 1;
		pthread_mutex_unlock(&data->vars->stop);
		data->vars->dead_count++;
		pthread_mutex_unlock(&data->vars->death);
		return (1);
	}
	return (0);
}

void	ft_usleep(int i, t_philo_data *data)
{
	long			t;

	t = get_time();
	while (get_time() - t < i)
	{
		if (check_dead(data) == 1)
			return ;
		usleep(100);
	}
}
