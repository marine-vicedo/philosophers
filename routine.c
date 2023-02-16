/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:59 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/16 13:54:36 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	print_msg(philo, THINK);
	usleep(400);
}

void	ft_sleep(t_philo *philo)
{
	print_msg(philo, SLEEP);
	usleep(philo->data->time_sleep * 1000);
}

int	ft_eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (0);
	print_msg(philo, EAT);
	pthread_mutex_lock(&philo->data->meal);
	philo->last_meal = ft_get_time();
	if (philo->x_meals != -1)
		philo->x_meals++;
	pthread_mutex_unlock(&philo->data->meal);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks
	[ft_fork1(&philo->r_fork, &philo->l_fork)]);
	pthread_mutex_unlock(&philo->data->forks
	[ft_fork2(&philo->r_fork, &philo->l_fork)]);
	return (1);
}
