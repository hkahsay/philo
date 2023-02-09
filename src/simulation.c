/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:16 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/09 12:22:44 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	take_fork(t_philo *philo)
{
	long int	time;
	// pthread_mutex_lock(philo->l_fork);
	// pthread_mutex_lock(philo->r_fork);
	time = get_time_in_ms();
	if (philo->dead == 0)
	{
		display_status(time, philo, GREEN"philo has taken fork\n");
	}
	// pthread_mutex_lock(philo->l_fork);
	// pthread_mutex_lock(philo->r_fork);
}

void	eat_philo(t_philo	*philo)
{
	long int	time;
	
	time = get_time_in_ms();
	if (philo->dead == 0)
	{
		display_status(time, philo, RED"philo is eating\n");
	}
	// philo->nb_of_meals++;
	// philo->finish_eat = ft_usleep();
	
}