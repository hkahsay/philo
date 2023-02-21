/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:57 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/21 16:06:13 by hkahsay          ###   ########.fr       */
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

long int	actual_time_msec(void)
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
// actual_time_msec = timestamp;
void	ms_sleep(int m_sec)
{
	long int	start_time_ms;

	start_time_ms = actual_time_msec();
	while (actual_time_msec() - start_time_ms < m_sec)
		usleep(m_sec);
}

long int	elapsed_time(t_info	*info)
{
	info->end = actual_time_msec();
	return (info->end - info->time_to_start);
}

void	display_status(long int t_ms, t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->info->status));
	if (t_ms >= 0)
		printf(WHITE"time  %ld  philo %d %s\n ", t_ms, philo->philo_id, str);
	pthread_mutex_unlock(&(philo->info->status));
}
