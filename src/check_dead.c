/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:31 by hkahsay           #+#    #+#             */
/*   Updated: 2023/03/02 17:13:41 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	*check_dead(void *args)
{
	t_philo		*philo;

	philo = args;
	while (philo->info->stop != 1)
	{
		check_philo_eat_enough(philo->info);
		philo_death_check(philo->info);
	}
	return (NULL);
}

void	check_philo_eat_enough(t_info *info)
{
	int	meal;
	int	i;
	int	finished;

	meal = 0;
	i = -1;
	while (++i < info->nbr_of_philosophers)
	{
		pthread_mutex_lock(&info->philo[i].mutex_meal_count);
		finished = (info->philo[i].meal_counter >= info->nb_of_meals && info->nb_of_meals != -1);
		pthread_mutex_unlock(&info->philo[i].mutex_meal_count);
		if (finished)
		{
			// pthread_mutex_unlock(&info->philo[i].mutex_meal_count);
			meal++;
			if (meal == info->nbr_of_philosophers)
			{
				pthread_mutex_lock(&info->mutex_dead_stop);
				// info->philo->dead = 1;
				info->stop = 1;
				pthread_mutex_unlock(&info->mutex_dead_stop);
				display_status(elapsed_time(info), info->philo, YELLOW"simulation is done\n");
				// break ;
				exit (0);
			}
		}
	}
}

void	philo_death_check(t_info *info)
{
	int			i;
	long int	time;

	i = -1;
	time = elapsed_time(info);
	while (++i < info->nbr_of_philosophers)
	{
		pthread_mutex_lock(&info->philo[i].mutex_last_meal);
		if (time - info->philo[i].last_meal
			>= info->time_to_die)
		{
			pthread_mutex_unlock(&info->philo[i].mutex_last_meal);
			pthread_mutex_lock(&info->mutex_dead_stop);
			info->stop = 1;
			pthread_mutex_unlock(&info->mutex_dead_stop);
			// pthread_mutex_lock(&info->mutex_dead_stop);
			if (info->stop == 1)
			{
				pthread_mutex_unlock(&info->mutex_dead_stop);
				pthread_mutex_unlock(&info->mutex_dead_stop);
				display_status(time, info->philo, YELLOW"philo is dead\n");
				info->stop = 1;
				pthread_mutex_unlock(&info->mutex_dead_stop);	
				break ;
			}
			// pthread_mutex_lock(&info->mutex_dead_stop);
		}
		pthread_mutex_unlock(&info->philo[i].mutex_last_meal);	
	}
}
