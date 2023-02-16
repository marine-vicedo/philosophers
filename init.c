/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/03 18:20:23 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mutexes(t_param *data)
{
	int	i;

	i = 0;
	while (i++ < data->nb_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(&data->death, NULL);
}

void	init_mutexes(t_param *data)
{
	int	i;

	i = 0;
	while (i++ < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->meal, NULL);
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(&data->death, NULL);
}

void	init_philo(t_param *data)
{
	int	i;

	i = 0;
	while (i++ < data->nb_philo)
	{
		data->philos[i].id = i;
		data->philos[i].x_meals = 0;
		data->philos[i].data = data;
		data->philos[i].last_meal = ft_get_time();
		if (i == 1)
			data->philos[i].r_fork = data->nb_philo;
		else
			data->philos[i].r_fork = i - 1;
		data->philos[i].l_fork = i;
	}
}

void	init_data(char **av, t_param *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->time_start = 0;
	data->nb_meals = -1;
	data->died = FALSE;
	data->done = FALSE;
	if (av[5])
	{
		data->nb_meals = ft_atoi(av[5]);
		if (data->nb_meals == 0)
			msg_error("Philosophers must eat at least once.");
	}
	if (data->nb_philo < 1)
		msg_error("Need one or more philosopher");
	if (data->nb_philo >= 250)
		msg_error("Too many philos");
	if (data->time_die == 0 || data->time_eat == 0 || data->time_sleep == 0)
		msg_error("invalid arguments");
	init_mutexes(data);
}
