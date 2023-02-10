/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:16 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/10 19:28:33 by hkahsay          ###   ########.fr       */
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
		philo->n_meals++;
	pthread_mutex_unlock(&philo->info->mutex_eat);
	ms_sleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	display_status(time, philo, BLUE"philo is sleeping");
	ms_sleep(philo->info->time_to_sleep);
}

// void	first_philo(t_philo *philo)
// {
// 	long int	time;

// 	time = elapsed_time(philo->info->time_to_start, actual_time_msec());
// 	display_status()
// }

// int	all_philo_eat(t_philo *philo)
// {
// 	if (philo->info->first_philo)
// 		philo = philo->info->first_philo;
// 	while (philo)
// 	{
// 		if (philo->info->nb_of_meals == -1)
// 			return (1);
// 		if (philo->n_meals < philo->info->nb_of_meals)
// 			return (0);
// 		philo = philo->next;
// 	}
// 	return (1);
// }
