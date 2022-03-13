/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:29:56 by rimney            #+#    #+#             */
/*   Updated: 2022/03/03 23:20:53 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_assign(char **argv, t_philosophers *philo)
{
	philo->philosopher = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	philo->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->each_time = ft_atoi(argv[5]);
	philo->index = 0;
}

// void	ft_eat(t_philosophers *philo)
// {
	
	
// }

void	*ft_routine(void *p)
{
	t_philosophers *philo = (t_philosophers *)p;
	if(philo->index != philo->number_of_philosophers - 1)
	{
		printf("%d < index\n", philo->index);
		return (0);
	}
	static int i = 0;
	while(i < philo->index)
	{
		printf("Philo %d has taken a fork\n", i + 1);
		pthread_mutex_lock(&philo->forks[i]);
		pthread_mutex_lock(&philo->forks[i + 1 % philo->number_of_philosophers]);
		printf("Philo %d is eating\n", i + 1);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->forks[i]);
		pthread_mutex_unlock(&philo->forks[i + 1 % philo->number_of_philosophers]);
		printf("Philo %d is sleeping\n", i + 1);
		usleep(philo->time_to_sleep * 1000);
		i += 1;
	}
	return (0);
}

void	ft_create_threads(t_philosophers *philo)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while(j < philo->number_of_philosophers)
	{
		pthread_mutex_init(&philo->forks[j], 0);
		j++;
	}
	while(philo->index < philo->number_of_philosophers)
	{
		pthread_create(&philo->philosopher[philo->index], NULL, ft_routine, philo);
		pthread_join(philo->philosopher[philo->index], 0);
		philo->index++;
	}
	while(philo->index > philo->number_of_philosophers)
	{
		pthread_join(philo->philosopher[philo->index], 0);
		philo->index -= 1;
	}

}

int	main(int argc, char **argv)
{
	t_philosophers philo;

	ft_assign(argv, &philo);
	ft_create_threads(&philo);
}