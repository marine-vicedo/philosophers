/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:40 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/13 16:10:43 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Usage : 
./philo 4 410 200 200
        +-|---|---|-- philo_nb
          +---|---|-- time_die
              +---|-- time_eat
                  +-- time_slp */

#include "philo.h"

int	arg_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (0);
	while (av[i])
	{
		if (arg_is_digit(av[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_param	data;

	if (!check_args(ac, av))
		msg_error("invalid arguments");
	init_data(av, &data);
	init_philo(&data);
	start_simulation(&data);
}

//printf("%d a sa fork droite %d\n", data.philos[1].id,
//	data.philos[1].r_fork);
//printf("%d a sa fork gauche %d\n", data.philos[1].id,
//	data.philos[1].l_fork);