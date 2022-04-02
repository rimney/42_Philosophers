/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosohpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:42:37 by rimney            #+#    #+#             */
/*   Updated: 2022/04/02 23:20:40 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int    ft_assign(int argc, char **argv, t_args *args) // tested and it works fine <3.
{
    args->philo_num = ft_atoi(argv[1]);
    args->time_to_die = ft_atoi(argv[2]);
    args->time_to_eat = ft_atoi(argv[3]);
    args->time_to_sleep = ft_atoi(argv[4]);
    args->each_time = 0;
    if (argc == 6)
        args->each_time = ft_atoi(argv[5]);
    return (0);
}

void    test(t_args *args)
{
    printf("Number of Philosophers : %d\n", args->philo_num);
    printf("Time_to_die : %d\n", args->time_to_die);
    printf("Time_to_eat : %d\n", args->time_to_eat);
    printf("Time_to_sleep : %d\n", args->time_to_sleep);
    printf("Each time : %d\n", args->each_time);
}

int main(int argc, char **argv)
{
    t_args args;
    t_philo philo;
    
    if(!ft_check_input(argc, argv))
        return (printf("Wrong input\n"), 0);
    ft_assign(argc, argv, &args);

    return (0);
}