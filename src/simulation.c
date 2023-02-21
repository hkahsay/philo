/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:16 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/21 17:47:46 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

int	take_fork(t_philo *philo)
{
	long int	time;
	int			is_dead;

	time = elapsed_time(philo->info);
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
	pthread_mutex_lock(&philo->info->mutex_dead);
	is_dead = philo->dead;
	pthread_mutex_unlock(&philo->info->mutex_dead);
	if (is_dead == 0)
	{
		display_status(time, philo, GREEN"philo has taken L_fork\n");
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
	else
		philo->meal_counter++;
	pthread_mutex_unlock(&philo->info->mutex_eat);
	ms_sleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	display_status(elapsed_time(philo->info), philo, BLUE"philo is sleeping");
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
