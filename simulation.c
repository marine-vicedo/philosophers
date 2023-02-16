/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:34 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/16 15:07:51 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_died(t_philo *philo)
{
	if (philo->data->nb_meals != -1
		&& (philo->x_meals == philo->data->nb_meals))
		return (TRUE);
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->died == TRUE)
	{
		pthread_mutex_unlock(&philo->data->death);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->death);
	return (FALSE);
}

void	wait_philo(t_philo *philo)
{
	if (philo->id % 2)
		usleep(philo->data->time_sleep * 1000);
	if (philo->id > 50)
		usleep(philo->id * 1500);
}

void	*philosophers(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	wait_philo(philo);
	while (1)
	{
		if (ft_check_died(philo))
			break ;
		if (ft_eat(philo) == 0)
			break ;
		if (ft_check_died(philo))
			break ;
		ft_sleep(philo);
		if (ft_check_died(philo))
			break ;
		ft_think(philo);
	}
	return (NULL);
}

void	start_simulation(t_param *data)
{
	int			i;
	pthread_t	thread[250];

	i = 0 ;
	data->time_start = ft_get_time();
	while (i++ < data->nb_philo)
		pthread_create(&(thread[i]), NULL, &philosophers, &data->philos[i]);
	ft_monitor(data);
	i = 0;
	while (i++ < data->nb_philo)
		pthread_join(thread[i], NULL);
	ft_destroy_mutexes(data);
}
