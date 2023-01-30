/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:52:01 by hkahsay           #+#    #+#             */
/*   Updated: 2023/01/30 14:47:34 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

static int	valid_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 6)
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

int	parsing(int argc, char **argv, t_philo *philo)
{
	if (valid_arguments(argc, argv))
	{
		philo->number_of_philosophers = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo->number_of_meals = ft_atoi(argv[5]);
	}
	else
	{
		printf("Incorrect number of arguments\n");
		return (0);
	}
	return (1);
}
