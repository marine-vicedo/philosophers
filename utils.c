/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:45 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/13 11:14:57 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec % 10000) * 1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX)
		return (-1);
	return (res);
}

void	print_msg(t_philo *philo, int id)
{
	pthread_mutex_lock(&philo->data->msg);
	if (id == EAT)
		printf("%lld %d is eating\n",
			(ft_get_time() - philo->data->time_start), philo->id);
	if (id == FORK)
		printf("%lld %d has taken a fork\n",
			(ft_get_time() - philo->data->time_start), philo->id);
	if (id == SLEEP)
		printf("%lld %d is sleeping\n",
			(ft_get_time() - philo->data->time_start), philo->id);
	if (id == THINK)
		printf("%lld %d is thinking\n",
			(ft_get_time() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->msg);
}

int	msg_error(char *str)
{
	printf("%s\n", str);
	exit (0);
}
