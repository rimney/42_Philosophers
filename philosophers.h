/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:34:14 by rimney            #+#    #+#             */
/*   Updated: 2022/04/07 20:41:55 by rimney           ###   ########.fr       */
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
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				each_time;
	int				out;
	unsigned int	time;
	pthread_mutex_t	printing;
}	t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	t_args			*args;
	int				max_eat;
	int				dead;
	int				died;
}	t_philo;

int				ft_atoi(char *str);
int				ft_check_input(int argc, char **argv);
int				ft_get_time(void);
void			ft_print_message(char *str, int id, t_args *args);
int				ft_assign(int argc, char **argv, t_args *args);
void			ft_sleep(int x);
void			ft_philo_activity(t_philo *philo);
void			ft_assign_values(t_philo *philo, t_args *args);
#	endif