/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:16 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/01 17:21:31 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	taking_fork()
{
	pthread_mutex_t	fork;
	int	i;
	
	i = 0
	while (i < 2)
	{
		/* code */
	}
	
}

void	philo_is_eating(t_philo	*philo)
{
	printf("philo is eating");
	philo->nb_of_meals++;
	philo->finish_eat = ft_usleep();
	
}