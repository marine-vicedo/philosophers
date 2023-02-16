/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:39:26 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/03 18:55:12 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_fork1(int *r_fork, int *l_fork)
{
	if (*r_fork == *l_fork)
		return (*l_fork);
	else if (*r_fork < *l_fork)
		return (*r_fork);
	return (*l_fork);
}

int	ft_fork2(int *r_fork, int *l_fork)
{
	if (*r_fork == *l_fork)
		return (*l_fork);
	if (*r_fork > *l_fork)
		return (*r_fork);
	return (*l_fork);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[1]);
	print_msg(philo, FORK);
	pthread_mutex_unlock(&philo->data->forks[1]);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks
	[ft_fork1(&philo->r_fork, &philo->l_fork)]);
	if (ft_check_died(philo) == TRUE)
	{
		pthread_mutex_unlock(&philo->data->forks
		[ft_fork1(&philo->r_fork, &philo->l_fork)]);
		return (0);
	}
	print_msg(philo, FORK);
	pthread_mutex_lock(&philo->data->forks
	[ft_fork2(&philo->r_fork, &philo->l_fork)]);
	if (ft_check_died(philo) == TRUE)
	{
		pthread_mutex_unlock(&philo->data->forks
		[ft_fork2(&philo->r_fork, &philo->l_fork)]);
		pthread_mutex_unlock(&philo->data->forks
		[ft_fork1(&philo->r_fork, &philo->l_fork)]);
		return (0);
	}
	print_msg(philo, FORK);
	return (1);
}
