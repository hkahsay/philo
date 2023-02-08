/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:30:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/08 17:39:25 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"
#include"../philo.h"

//the next each other should not eat at the same time so we find % 2 so if even nbr 
void	*routine(void *arg)
{
	t_philo	*philo;
	int		n_philo;

	philo = (t_philo *)arg;
	n_philo = philo->info->nbr_of_philosophers;
	if(n_philo % 2 == 0)
		ft_usleep(philo->info->time_to_eat / 10);
	while (philo->info->dead == 0)
	{
		take_fork(philo);
		eat_philo(philo);
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
		info->philo[i].info = info;
		info->philo[i].last_meal = 0;
		info->philo[i].n_meals = 0;
		info->philo[i].l_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(info->philo[i].l_fork, NULL);
		if (i == info->nbr_of_philosophers - 1)
			info->philo[i].r_fork = info->philo[i].l_fork;
		else
			info->philo[i].r_fork = info->philo[i + 1].l_fork;
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
	info->time_to_start = get_time_in_ms();
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

int	is_dead(t_info	*info)
{
	if (info->philo->n_meals == 0)
		printf("philo is dead\n");
	return (0);
}
