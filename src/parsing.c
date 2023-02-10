/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:52:01 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/10 19:31:08 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

static int	valid_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (i < argc)
		{
			if (!is_num_l(argv[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	parsing(int argc, char **argv, t_info *info)
{
	pthread_mutex_init(&info->mutex_eat, NULL);
	pthread_mutex_init(&info->mutex_stop, NULL);
	pthread_mutex_init(&info->status, NULL);
	if (valid_arguments(argc, argv))
	{
		info->nbr_of_philosophers = ft_atoi(argv[1]);
		info->time_to_die = ft_atoi(argv[2]);
		info->time_to_eat = ft_atoi(argv[3]);
		info->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			info->nb_of_meals = ft_atoi(argv[5]);
	}
	else
		info->nb_of_meals = -1;
	return (1);
}
