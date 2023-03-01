/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:31 by hkahsay           #+#    #+#             */
/*   Updated: 2023/03/01 16:55:59 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	*check_dead(void *args)
{
	t_philo		*philo;

	philo = args;
	while (philo->dead != 1)
	{
		philo_death_check(philo->info);
	}
	return (NULL);
}

void	check_philo_eat_enough(t_info *info)
{
	int	meal;
	int	i;

	meal = 0;
	i = -1;
	while (++i < info->nbr_of_philosophers)
	{
		pthread_mutex_lock(&info->philo[i].mutex_eat);
		if ((info->philo[i].meal_counter >= info->nb_of_meals \
			&& info->nb_of_meals != -1))
		{
			pthread_mutex_unlock(&info->philo[i].mutex_eat);
			meal++;
			if (meal == info->nbr_of_philosophers)
			{
				pthread_mutex_lock(&info->philo[i].mutex_dead);
				info->philo[i].dead = 1;
				pthread_mutex_unlock(&info->philo[i].mutex_dead);
			}
		}
		else
			pthread_mutex_unlock(&info->philo[i].mutex_eat);
	}
}

void	philo_death_check(t_info *info)
{
	int			i;
	long int	time;
	int			is_finished;

	i = -1;
	time = elapsed_time(info);
	check_philo_eat_enough(info);
	while (++i < info->nbr_of_philosophers)
	{
		pthread_mutex_lock(&(info->philo[i].mutex_last_meal));
		is_finished = time - info->philo[i].last_meal
			>= info->time_to_die;
		pthread_mutex_unlock(&(info->philo[i].mutex_last_meal));
		if (is_finished)
		{
			pthread_mutex_lock(&info->philo->mutex_dead);
			info->philo->dead = 1;
			pthread_mutex_unlock(&info->philo->mutex_dead);
			if (info->philo->dead == 1)
			{
				display_status(time, info->philo, YELLOW"philo is dead\n");
				break ;
			}
		}
	}
}
