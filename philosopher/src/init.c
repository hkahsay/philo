/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/01 11:58:52 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	create_thread(t_philo *philo)
{
	pthread_t	threads;
	int			nbr_of_philos;
	
	nbr_of_philos = philo->number_of_philosophers;
	threads = malloc(sizeof(pthread_t) * nbr_of_philos);
	
}

void	create_mutex()
{
	
}
