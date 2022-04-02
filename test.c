/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:33:49 by rimney            #+#    #+#             */
/*   Updated: 2022/04/02 23:02:16 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_get_time(int current_time)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return(time.tv_sec - current_time);
}

int main()
{
    struct timeval time;
	gettimeofday(&time, NULL);
    int ret;
	int i;
	int t  = 0;

	i = 0;
	t = ft_get_time(time.tv_sec);
	while(i < 10000000)
	{
		ret = ft_get_time(time.tv_sec);
		if(ret - t == 1 )
			printf("%d \n", ret);
	//sleep(1);
		i++;
	}
	return (0);
}