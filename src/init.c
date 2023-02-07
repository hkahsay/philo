/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/06 15:19:25 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"
#include"../philo.h"


void *routine(void *arg) {
	t_info * info;
	
	info = arg;
	printf("i am %d out of %d\n", info->j, info->nbr_of_philosophers);
	return arg;
}

int	create_threads(t_info *info)
{
	int			nbr_of_philos;
	
	nbr_of_philos = info->nbr_of_philosophers;
	// threads = malloc(sizeof(pthread_t) * nbr_of_philos);
	info = malloc(sizeof(t_info) * nbr_of_philos);
	
	int			i = 0;
	while (i < nbr_of_philos)
	{
		info[i].nbr_of_philosophers = i;
		info[i].nbr_of_philosophers = nbr_of_philos;
		pthread_create(&info->philo[i].tid, NULL, routine, &info[i]);
		i++;
	}
	i = 0;
	while (i < nbr_of_philos)
	{
		pthread_join(info->philo[i].tid, NULL);
		i++;
	}
}

void	init_mutex(t_info *info)
{
	int	nbr_of_forks;
	int	i;
	
	nbr_of_forks = forks->mutex_fork 
}