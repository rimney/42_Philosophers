/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:45:11 by rimney            #+#    #+#             */
/*   Updated: 2022/04/02 21:23:48 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_atoi(char *str)
{
    int i;
    int num;
    int sign;

    i = 0;
    num = 0;
    sign = 1;
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * sign);
}

int ft_is_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
	return (1);
}

int ft_check_input(int argc, char **argv)
{
    int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_digit(argv[i]) || argc < 5 || argc > 6 || ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}