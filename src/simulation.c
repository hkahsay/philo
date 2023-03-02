/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:16 by hkahsay           #+#    #+#             */
/*   Updated: 2023/03/02 17:21:41 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

int	take_fork(t_philo *philo)
{
	// long int	time;

	// time = elapsed_time(philo->info);
	pthread_mutex_lock(&philo->info->mutex_dead_stop);
	if (philo->info->stop == 0)
	{
		pthread_mutex_unlock(&philo->info->mutex_dead_stop);
		pthread_mutex_lock(philo->l_fork);
		display_status(elapsed_time(philo->info), philo, GREEN"philo has taken L_fork\n");
		pthread_mutex_lock(&philo->r_fork);
		display_status(elapsed_time(philo->info), philo, GREEN"philo has taken R_fork\n");
	}
	pthread_mutex_unlock(&philo->info->mutex_dead_stop);
	return (0);
}

void	eat_philo(t_philo	*philo)
{
	long int	time;

	time = elapsed_time(philo->info);
	pthread_mutex_lock(&philo->mutex_eat);
	display_status(time, philo, RED"philo is eating\n");
	pthread_mutex_lock(&philo->mutex_last_meal);
	philo->last_meal = elapsed_time(philo->info);
	pthread_mutex_unlock(&philo->mutex_last_meal);
	pthread_mutex_lock(&philo->mutex_meal_count);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->mutex_meal_count);
	ms_sleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->mutex_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex_dead_stop);
	if (philo->info->stop == 0)
	{
		printf("sleep%d\n", philo->info->stop);
		display_status(elapsed_time(philo->info), philo, BLUE"philo is sleeping");
		ms_sleep(philo->info->time_to_sleep);
		pthread_mutex_unlock(&philo->info->mutex_dead_stop);
	}
	pthread_mutex_unlock(&philo->info->mutex_dead_stop);
	
}

void	one_philo(t_philo *philo)
{
	long int	time;

	time = elapsed_time(philo->info);
	pthread_mutex_lock(&philo->r_fork);
	display_status(time, philo, GREEN"philo has taken R_fork\n");
	pthread_mutex_unlock(&philo->r_fork);
	philo->info->stop++;
	ms_sleep(philo->info->time_to_die);
	time = elapsed_time(philo->info);
	display_status(time, philo, RED"philo is died\n");
	return ;
}
