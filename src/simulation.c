/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:16 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/20 16:44:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

int	take_fork(t_philo *philo)
{
	long int	time;

	time = elapsed_time(philo->info);
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
	if (philo->dead == 0)
	{
		display_status(time, philo, GREEN"philo has taken l_fork\n");
		display_status(time, philo, GREEN"philo has taken R_fork\n");
	}
	return (0);
}

void	eat_philo(t_philo	*philo)
{
	long int	time;

	time = elapsed_time(philo->info);
	display_status(time, philo, RED"philo is eating\n");
	pthread_mutex_lock(&(philo->info->mutex_eat));
	philo->last_meal = elapsed_time(philo->info);
	if (philo->info->nb_of_meals == -1)
		philo->meal_counter++;
	pthread_mutex_unlock(&philo->info->mutex_eat);
	ms_sleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	display_status(time, philo, BLUE"philo is sleeping");
	ms_sleep(philo->info->time_to_sleep);
}

void	one_philo(t_philo *philo)
{
	long int	time;

	time = elapsed_time(philo->info);
	pthread_mutex_lock(&philo->r_fork);
	ms_sleep(philo->info->time_to_die);
	display_status(time, philo, RED"philo is died\n");
	exit(0);
}

// void	*check_dead(void *args)
// {
// 	t_philo		*philo;

// 	philo = args;
// 	while (philo->dead != 1)
// 		check_philo_eat_enough(philo->info);
// 	return (NULL);
// }

// void	check_philo_eat_enough(t_info *info)
// {
// 	int			i;
// 	int			meal;
	
// 	i = 0;
// 	meal = 0;
// 	// curr_time = actual_time_msec();
// 	while (i < info->nbr_of_philosophers)
// 	{
// 		if (info->nb_of_meals != -1
// 			&& info->philo[i].meal_counter >= info->nb_of_meals)
// 		{
// 			meal++;
// 			if (meal == info->nbr_of_philosophers)
// 			{
// 				printf("last meal%d\n", info->philo->last_meal);
// 				info->philo->dead = 1;
// 			}
// 		}
// 		if (elapsed_time(info) - info->philo[i].last_meal
// 			>= info->time_to_die)
// 		{
// 			info->philo->dead = 1;
// 			if (info->philo->dead == 1)
// 			{
// 				display_status(elapsed_time(info), info->philo, "philo is dead\n");
// 				break;
// 			}
// 		}
// 		i++;
// 	}
// }
