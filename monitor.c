/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:49:45 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/13 15:55:42 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitor_death(t_param *data, int i, long long l_meal)
{
	if (ft_get_time() - l_meal >= data->time_die)
	{
		pthread_mutex_lock(&data->death);
		data->died = TRUE;
		pthread_mutex_unlock(&data->death);
		pthread_mutex_lock(&data->msg);
		printf("%lld %d died\n", ft_get_time()
			- data->time_start, data->philos[i].id);
		pthread_mutex_unlock(&data->msg);
	}
	return ;
}

void	ft_monitor(t_param *data)
{
	int			i;
	long long	l_meal;

	i = 1;
	while (1)
	{
		if (data->died == 1)
			break ;
		pthread_mutex_lock(&data->meal);
		l_meal = data->philos[i].last_meal;
		if (data->philos[i].x_meals == data->nb_meals)
		{
			pthread_mutex_unlock(&data->meal);
			break ;
		}
		pthread_mutex_unlock(&data->meal);
		ft_monitor_death(data, i, l_meal);
		if (i == data->nb_philo)
			i = 0;
		i++;
	}
}
