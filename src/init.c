/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/03/09 15:48:02 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"
#include"../philo.h"

//the next each other should not eat at the same time so we find % 2 
//so if even nbr 
void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		ms_sleep(philo->info->time_to_eat);
	while (1)
	{
		if (take_fork(philo))
			break ;
		pthread_mutex_lock(&philo->info->mutex_dead);
		if (philo->info->dead == 0)
		{
			pthread_mutex_unlock(&philo->info->mutex_dead);
			eat_philo(philo);
			philo_sleep(philo);
			pthread_mutex_lock(&philo->info->mutex_dead);
		}
		// if (philo->info->dead == 0)
		// {
		// 	philo_sleep(philo);
		// 	pthread_mutex_lock(&philo->info->mutex_dead);
		// }
		if (philo->info->dead == 0)
		{
			pthread_mutex_unlock(&philo->info->mutex_dead);
			display_status(elapsed_time(philo->info),
				philo, YELLOW"philo is thinking");
			usleep(50);
			pthread_mutex_lock(&philo->info->mutex_dead);
		}
		if (philo->info->dead)
		{
			pthread_mutex_unlock(&philo->info->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(&philo->info->mutex_dead);
	}
	return (NULL);
}

t_info	*set_philos(t_info	*info)
{
	int	i;

	info->philo = malloc(sizeof(t_philo) * info->nbr_of_philosophers);
	info->time_to_start = actual_time_msec();
	i = 0;
	while (i < info->nbr_of_philosophers)
	{
		info->philo[i].philo_id = i + 1;
		pthread_mutex_init(&info->philo[i].mutex_last_meal, NULL);
		pthread_mutex_init(&info->philo[i].mutex_eat, NULL);
		pthread_mutex_init(&info->philo[i].r_fork, NULL);
		if (i != 0)
			info->philo[i].l_fork = &info->philo[i - 1].r_fork;
		info->philo[i].info = info;
		info->philo[i].last_meal = 0;
		info->philo[i].meal_counter = 0;
		info->dead = 0;
		i++;
	}
	info->philo[0].l_fork = &info->philo[info->nbr_of_philosophers - 1].r_fork;
	pthread_mutex_init(&info->mutex_dead, NULL);
	return (info);
}

int	create_threads(t_info *info)
{
	int	i;

	set_philos(info);
	if (info->nbr_of_philosophers == 1)
		one_philo(info->philo);
	else
	{
		i = 0;
		while (i < info->nbr_of_philosophers)
		{
			if (pthread_create(&info->philo[i].tid, NULL,
					&routine, (void *)&(info->philo[i])) != 0)
				return (-1);
			i++;
		}
		pthread_create(&info->tid_dead, NULL, &check_dead, (void *) info->philo);
		i = 0;
		while (i < info->nbr_of_philosophers)
		{
			if (pthread_join(info->philo[i].tid, NULL) != 0)
				return (-1);
			i++;
		}
		pthread_join(info->tid_dead, NULL);
	}
	return (0);
}
