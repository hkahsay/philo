/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/01 17:53:12 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"
#include"../philo.h"


void *routine(void *arg) {
	t_info * info;
	
	info = arg;
	printf("i am %d out of %d\n", info->j, info->number_of_philosophers);
	return arg;
}

void	create_threads(t_info *info)
{
	int			nbr_of_philos;
	pthread_t	*threads;
	// t_philo *philo;
	
	nbr_of_philos = info->number_of_philosophers;
	threads = malloc(sizeof(pthread_t) * nbr_of_philos);
	info = malloc(sizeof(t_info) * nbr_of_philos);
	
	int			i = 0;
	while (i < nbr_of_philos)
	{
		info[i].j = i;
		info[i].number_of_philosophers = nbr_of_philos;
		pthread_create(&threads[i], NULL, routine, &info[i]);
		i++;
	}
	i = 0;
	while (i < nbr_of_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	init_mutex(t_info *info)
{
	int	nbr_of_forks;
	int	i;
	
	nbr_of_forks = forks->mutex_fork 
}