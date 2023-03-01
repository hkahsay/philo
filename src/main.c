/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:55:34 by hkahsay           #+#    #+#             */
/*   Updated: 2023/03/01 15:18:28 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	*destroy_m(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->nbr_of_philosophers)
	{
		pthread_mutex_destroy(&philo[i].l_fork);
		pthread_mutex_destroy(&philo[i].r_fork);
		pthread_mutex_destroy(&philo->mutex_dead);
		pthread_mutex_destroy(&philo[i].mutex_last_meal);
	}
	return (0);
}

int	main(int agc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	parsing(agc, argv, info);
	create_threads(info);
	destroy_m(info->philo);
	free(info->philo);
	free(info);
	return (0);
}
