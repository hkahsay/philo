/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/04 17:55:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"


void *routine(void *arg) {
	t_info * info = arg;
	// pthread_t	tid;
	t_philo	*philo;
	
	philo = NULL;
	while (philo->number_of_philosophers)
	{
		// philo_eating(philo->info);
		printf("nb of meals");
	}
	
	printf("i am %d out of %d\n", info->j, info->philo->number_of_philosophers);
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
		infos[i].nb_meals = 0;
		infos[i].last_eat = 0;
		infos[i].philo = philo;
		// printf("%d, %ld, %d\n",infos[i].nb_meals, infos[i].last_eat, infos[i].j);
		pthread_create(&threads[i], NULL, routine, &infos[i]);
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