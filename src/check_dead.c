/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:31 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/21 18:00:45 by hkahsay          ###   ########.fr       */
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
	int	is_finished;

	meal = 0;
	i = 0;
	while (i < info->nbr_of_philosophers)
	{
		pthread_mutex_lock(&info->mutex_eat);
		is_finished = (info->philo[i].meal_counter >= info->nb_of_meals \
			&& info->nb_of_meals != -1);
		pthread_mutex_unlock(&info->mutex_eat);
		if (is_finished)
		{
			meal++;
			if (meal == info->nbr_of_philosophers)
			{
				pthread_mutex_lock(&info->mutex_dead);
				info->philo->dead = 1;
				pthread_mutex_unlock(&info->mutex_dead);
				if (info->philo->dead == 1)
					exit (0);
			}
		}
		i++;
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
		pthread_mutex_lock(&(info->mutex_eat));
		is_finished = time - info->philo[i].last_meal
			>= info->time_to_die;
		pthread_mutex_unlock(&(info->mutex_eat));
		if (is_finished)
		{
			pthread_mutex_lock(&info->mutex_dead);
			info->philo->dead = 1;
			display_status(time, info->philo, YELLOW"philo is dead\n");
			pthread_mutex_unlock(&info->mutex_dead);
			exit (0);
		}
	}
}
