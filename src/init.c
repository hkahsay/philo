/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/10 19:29:51 by hkahsay          ###   ########.fr       */
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
	if (n_philo % 2 == 0)
		ms_sleep(philo->info->time_to_eat / 10);
	while (1)
	{
		if (take_fork(philo))
			break ;
		if (philo->dead == 0)
		{
			eat_philo(philo);
			display_status(time, philo, YELLOW"philo is thinking");
			usleep(philo->info->time_to_think);
		}
	}
	return (NULL);
}

t_info	*set_philos(t_info	*info)
{
	int	i;

	i = 0;
	while (i < info->nbr_of_philosophers)
	{
		info->philo[i].philo_id = i;
		if (i == info->nbr_of_philosophers - 1)
			info->philo[i].r_fork = info->philo[i].l_fork;
		else
			info->philo[i].r_fork = info->philo[i + 1].l_fork;
		info->philo[i].info = info;
		info->philo[i].last_meal = 0;
		info->philo[i].n_meals = 0;
		info->philo[i].dead = 0;
		pthread_mutex_init(&info->philo[i].l_fork, NULL);
		if (info->time_to_start > info->time_to_eat)
			info->philo->dead = 1;
		i++;
	}
	return (info);
}

int	create_threads(t_info *info)
{
	int	nbr_of_philos;
	int	i;

	nbr_of_philos = info->nbr_of_philosophers;
	info->philo = malloc(sizeof(t_philo) * nbr_of_philos);
	info->time_to_start = actual_time_msec();
	set_philos(info);
	i = 0;
	while (i < nbr_of_philos)
	{
		if (pthread_create(&info->philo[i].tid, NULL,
				&routine, (void *)&(info->philo[i])) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < nbr_of_philos)
	{
		if (pthread_join(info->philo[i].tid, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

// int	is_dead(t_info	*info)
// {
// 	if (info->philo->n_meals == 0)
// 		printf("philo is dead\n");
// 	return (0);
// }
