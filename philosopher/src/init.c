/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/01 12:28:12 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"
#include"../philo.h"


void *routine(void *arg) {
	t_info * info = arg;
	printf("i am %d out of %d\n", info->j, info->config->number_of_philosophers);
	return arg;
}

void	create_threads(t_philo *philo)
{
	int			nbr_of_philos;
	pthread_t	*threads;
	t_info	   *infos;	
	
	nbr_of_philos = philo->number_of_philosophers;
	threads = malloc(sizeof(pthread_t) * nbr_of_philos);
	infos = malloc(sizeof(t_info) * nbr_of_philos);
	
	int			i = 0;
	while (i < nbr_of_philos)
	{
		infos[i].j = i;
		infos[i].config = philo;
		pthread_create(&threads[i], NULL, routine, &infos[i]);
		i++;
	}
	i = 0;
	while (i < nbr_of_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	

	
}

void	create_mutex()
{
	
}