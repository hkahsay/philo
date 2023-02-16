/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:16 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/15 14:43:24 by hkahsay          ###   ########.fr       */
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
	if (philo->info->nb_of_meals == 1)
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

int	check_philo_eat_enough(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->nbr_of_philosophers)
	{
		if (philo[i].info->nb_of_meals != 1
			&& philo->info->nb_of_meals == philo->meal_counter)
		{
			philo->dead = 1;
		}
		i++;
	}
	return (0);
}

void	*check_dead(void *args)
{
	t_philo		*philo;
	long int	curr_time;
	int			i;
	long int	time;

	i = 0;
	philo = (t_philo *)(args);
	curr_time = actual_time_msec();
	time = elapsed_time(philo->info);
	while (i < philo[i].info->nbr_of_philosophers)
	{
		if (curr_time - philo[i].last_meal
			>= philo[i].info->time_to_die)
		{
			philo[i].dead = 1;
			display_status(time, philo, "philo is dead\n");
			exit (0);
		}
		i++;
	}
	check_philo_eat_enough(philo);
	return (NULL);
}
