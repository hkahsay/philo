/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:16 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/08 17:39:00 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork)
	printf("philo has taken fork");
	// if (/* condition */)
	// {
	// 	/* code */
	// }
	
	
}

void	eat_philo(t_philo	*philo)
{
	printf("philo is eating");
	// philo->nb_of_meals++;
	// philo->finish_eat = ft_usleep();
	
}