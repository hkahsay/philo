/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:57 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/08 17:10:23 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

// int gettimeofday ( struct timeval *tp ,  struct timezone *tz )
// The gettimeofday() function gets the system’s clock time
// # include<sys/time.h> headerfile
// to change sec into milisec multiply by 1000
// to change microsec into milisec divide by 1000
// then add toget actual time in milisecond
//tp -> present time
// sec = (size_t)tp.tv_sec * 1000;
// usec = (size_t)tp.tv_usec / 1000;

long long	get_time_in_ms(void)
{
	struct timeval		tp;
	long int			actual_t_ms;

	gettimeofday(&tp, NULL);
	actual_t_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (actual_t_ms);
}

//  #include <unistd.h>

//        int usleep(useconds_t usec)
//    The usleep() function suspends execution of the calling thread
//        for (at least) usec microseconds
// get_time_in_ms = timestamp;
void	ft_usleep(int m_sec)
{
	long int	m_sleep;

	m_sleep = get_time_in_ms();
	while (get_time_in_ms() - m_sleep < m_sec)
		usleep(m_sec / 10);
}
void	dispaly_status(long int t_ms, t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->info->status));
	t_ms = get_time_in_ms() - philo->info->time_to_start;
	if ( )
}
