/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:34:14 by rimney            #+#    #+#             */
/*   Updated: 2022/04/02 20:57:12 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef struct args
{
	int philo_num;
	int	time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int	each_time;
	int status;
	pthread_mutex_t printing;
	unsigned int time;
	int beats;
}	t_args;

typedef struct s_philo
{
    int id;
    pthread_t thread_id;
    pthread_mutex_t fork;
    pthread_mutex_t *next_fork;
    t_args *args;
	int max_eat;
	unsigned int dead;
}	t_philo;

int ft_atoi(char *str);
int ft_check_input(int argc, char **argv);


# endif