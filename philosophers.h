/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:13:02 by rimney            #+#    #+#             */
/*   Updated: 2022/03/03 00:43:58 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct philosophers
{
	pthread_t *philosopher;
	pthread_mutex_t *forks;
	int number_of_philosophers;
	int time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	each_time;
}t_philosophers;
int	ft_atoi(char *str);

# endif 