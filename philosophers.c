/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:42:37 by rimney            #+#    #+#             */
/*   Updated: 2022/04/12 20:40:54 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_handle_norm(t_philo *philo, int flag, int index)
{
	if (flag == 0)
	{
		ft_sleep(philo->args->time_to_die);
		printf("%u 1 died\n", (philo->args->time_to_die));
		return ;
	}
	if (flag == 1)
	{
		pthread_mutex_lock(&philo->args->printing);
		printf("%u %d died\n", (ft_get_time()
				- philo->args->time), philo[index].id);
		return ;
	}
}

void	*ft_health_check(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < philo->args->philo_num)
		{
			if (philo->args->philo_num == 1)
			{
				ft_handle_norm(philo, 0, i);
				return (NULL);
			}
			else if (philo->args->out == (philo->args->philo_num
					* philo->args->each_time) && all(philo))
				return (NULL);
			else if (ft_get_time() - philo[i].dead > philo->args->time_to_die)
			{
				ft_handle_norm(philo, 1, i);
				usleep(1000);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*ft_routine(void *value)
{
	int			i;
	t_philo		*philo;

	philo = (t_philo *)value;
	i = 0;
	philo->dead = philo->args->time + philo->args->time_to_die;
	while (i < philo->args->each_time || !(philo->args->each_time))
	{
		ft_philo_activity(philo);
		i++;
	}
	return (NULL);
}

t_philo	*ft_create_threads(t_args *args)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * args->philo_num);
	if (!philo)
		return (printf("Threads allocation error\n"), NULL);
	while (i < args->philo_num)
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		i++;
	}
	i = 0;
	ft_assign_values(philo, args);
	args->time = ft_get_time();
	while (i < args->philo_num)
	{
		if (pthread_create(&philo[i].thread_id, NULL, &ft_routine, &philo[i]))
			return (printf("An error has been occured\n"), NULL);
		usleep(60);
		i++;
	}
	ft_health_check(philo);
	return (philo);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo;

	if (!ft_check_input(argc, argv) || argc == 1)
		return (printf("Wrong input\n"), 0);
	ft_assign(argc, argv, &args);
	pthread_mutex_init(&args.printing, NULL);
	philo = ft_create_threads(&args);
	if (!philo)
		return (0);
	pthread_mutex_destroy(&args.printing);
	free(philo);
	return (0);
}
