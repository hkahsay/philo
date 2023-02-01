/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:57 by hkahsay           #+#    #+#             */
/*   Updated: 2023/01/31 13:59:26 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

// int gettimeofday ( struct timeval *tp ,  struct timezone *tz )
// The gettimeofday() function gets the system’s clock time
// # include<sys/time.h> headerfile

time_t	get_time_in_ms(void)
{
	struct timeval	tp;
	time_t			res;

	gettimeofday(&tp, NULL);
	res = ((size_t)tp.tv_sec * 1000) + ((size_t)tp.tv_usec / 1000);
	return (res);
}

//  #include <unistd.h>

//        int usleep(useconds_t usec)
//    The usleep() function suspends execution of the calling thread
//        for (at least) usec microseconds
time_t	ft_usleep(t_philo	*philo)
{
	time_t	elapsed;

	elapsed = get_time_in_ms() - philo->time_to_start;
	return (elapsed);
}
