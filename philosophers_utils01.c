/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:09:21 by rimney            #+#    #+#             */
/*   Updated: 2022/04/07 21:42:26 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(int x)
{
	long	i;
	long	o;

	o = (long)x;
	i = ft_get_time();
	while (ft_get_time() - i < x)
		usleep(500);
}

int	ft_assign(int argc, char **argv, t_args *args)
{
	args->philo_num = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->each_time = 0;
	if (argc == 6)
	{
		args->each_time = ft_atoi(argv[5]);
		args->out = 0;
	}
	return (0);
}

void	ft_assign_values(t_philo *philo, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].dead = ft_get_time();
		philo[i].args = args;
		if (i == args->philo_num - 1)
			philo[i].next_fork = &philo[0].fork;
		else
			philo[i].next_fork = &philo[i + 1].fork;
		philo[i].died = 0;
		i++;
	}
}

void	ft_philo_activity(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_print_message("has taken a fork", philo->id, philo->args);
	pthread_mutex_lock(philo->next_fork);
	ft_print_message("has taken a fork", philo->id, philo->args);
	philo->dead = ft_get_time();
	ft_print_message("is eating", philo->id, philo->args);
	ft_sleep(philo->args->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
	ft_print_message("is sleeping", philo->id, philo->args);
	ft_sleep(philo->args->time_to_sleep);
	ft_print_message("is thinkng", philo->id, philo->args);
	philo->args->out += 1;
}
