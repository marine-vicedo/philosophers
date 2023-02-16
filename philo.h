/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:50 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/13 15:54:45 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

# define FALSE 0
# define TRUE 1
# define FORK 3
# define EAT 4
# define SLEEP 5
# define THINK 6
# define DIED 7
# define DONE 8

struct	s_param;

typedef struct s_philo
{
	int				id;
	int				x_meals;
	long long		last_meal;
	int				l_fork;
	int				r_fork;
	struct s_param	*data;
}	t_philo;

typedef struct s_param
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_meals;
	long long		time_start;
	int				died;
	int				done;
	t_philo			philos[250];
	pthread_mutex_t	forks[250];
	pthread_mutex_t	meal;
	pthread_mutex_t	msg;
	pthread_mutex_t	death;
}	t_param;

/* PARSING */
int			check_args(int ac, char **av);
int			arg_is_digit(char *str);

/* STRUCTS & MUTEXES */
void		init_data(char **av, t_param *data);
void		init_philo(t_param *data);
void		init_mutexes(t_param *data);
void		ft_destroy_mutexes(t_param *data);

/* UTILS */
int			ft_atoi(char *str);
int			msg_error(char *str);
void		print_msg(t_philo *philo, int id);
long long	ft_get_time(void);

/* SIMULATION & THREADS */
void		start_simulation(t_param *data);
void		*philosophers(void *arg);
void		wait_philo(t_philo *philo);
int			ft_check_died(t_philo *philo);

/* ROUTINE PHILO */
void		ft_think(t_philo *philo);
void		ft_sleep(t_philo *philo);
int			ft_eat(t_philo *philo);

/* TAKE FORKS*/
int			take_forks(t_philo *philo);
int			ft_fork1(int *r_fork, int *l_fork);
int			ft_fork2(int *r_fork, int *l_fork);
void		one_philo(t_philo *philo);

/* MONITOR */
void		ft_monitor(t_param *data);
void		ft_monitor_death(t_param *data, int i, long long l_meal);

#endif