/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/15 14:08:56 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"
#include"../philo.h"

//the next each other should not eat at the same time so we find % 2 
//so if even nbr 
void	*routine(void *arg)
{
	t_philo		*philo;
	int			n_philo;
	long int	time;

	philo = (t_philo *)arg;
	time = elapsed_time(philo->info);
	n_philo = philo->info->nbr_of_philosophers;
	if (philo->philo_id % 2 == 0)
		ms_sleep(philo->info->time_to_eat);
	while (philo->dead == 0)
	{
		if (take_fork(philo))
			break ;
		if (philo->dead == 0)
		{
			eat_philo(philo);
			display_status(time, philo, YELLOW"philo is thinking");
			ms_sleep(philo->info->time_to_think);
		}
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
		pthread_mutex_init(&info->philo[i].l_fork, NULL);
		if (i == info->nbr_of_philosophers - 1)
			info->philo[i].r_fork = info->philo[0].l_fork;
		else
			info->philo[i].r_fork = info->philo[i + 1].l_fork;
		info->philo[i].info = info;
		info->philo[i].last_meal = 0;
		info->philo[i].meal_counter = 0;
		info->philo[i].dead = 0;
		i++;
	}
	return (info);
}

int	create_threads(t_info *info)
{
	int	i;

	set_philos(info);
	if (info->nbr_of_philosophers == 1)
		one_philo(info->philo);
	i = 0;
	while (i < info->nbr_of_philosophers)
	{
		if (pthread_create(&info->philo[i].tid, NULL,
				&routine, (void *)&(info->philo[i])) != 0)
			return (-1);
		i++;
	}
	dead_philos_thread(info->philo);
	i = 0;
	while (i < info->nbr_of_philosophers)
	{
		if (pthread_join(info->philo[i].tid, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

// create thread for philo dead

int	dead_philos_thread(t_philo *philo)
{
	pthread_t	tid_dead;

	if (philo->info->nbr_of_philosophers == 1)
		one_philo(philo);
	// philo = malloc(sizeof(t_philo));
	if (pthread_create(&tid_dead, NULL, &check_dead, (void *) philo) != 0)
	{
		return (-1);
	}
	if (pthread_join(tid_dead, NULL) != 0)
		return (-1);
	return (0);
}
