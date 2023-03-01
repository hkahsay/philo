/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:52:01 by hkahsay           #+#    #+#             */
/*   Updated: 2023/03/01 12:53:58 by hkahsay          ###   ########.fr       */
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

//if i dont specify nb_meals i just assign
//nb_meal to 1 so aslong as nb_meal is 1 philos are going to eat their meal
int	parsing(int argc, char **argv, t_info *info)
{
	// pthread_mutex_init(&info->mutex_stop, NULL);
	pthread_mutex_init(&info->status, NULL);
	if (valid_arguments(argc, argv))
	{
		info->nbr_of_philosophers = ft_atoi_long(argv[1]);
		info->time_to_die = ft_atoi_long(argv[2]);
		info->time_to_eat = ft_atoi_long(argv[3]);
		info->time_to_sleep = ft_atoi_long(argv[4]);
		if (argc == 6)
			info->nb_of_meals = ft_atoi_long(argv[5]);
		else
			info->nb_of_meals = -1;
		if ((info->nb_of_meals < 1 && argc == 6)
			|| info->nbr_of_philosophers < 1 || info->time_to_die < 0
			|| info->time_to_eat < 0 || info->time_to_sleep < 0)
			return (1);
	}
	else
	{
		printf(RED"invalid arguments\n");
		exit(0);
	}
	return (1);
}
