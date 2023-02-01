/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:21:43 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/01 12:30:02 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<pthread.h>
# include<sys/time.h>
# include"philo.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483647
# define GREEN	"\033[1m\033[32m"
# define RED	"\033[1m\033[31m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

typedef	struct	s_philo
{
	pthread_mutex_t	mutex_fork;
	
	int				pos_fork;
 }	t_forks;
 

typedef struct s_philo
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_think;
	int		number_of_meals;
	int		l_fork;
	int		r_fork;
	time_t	time_to_start;
	pthread_mutex_t	mutex_fork;
	int				pos;
	int				free;
}	t_philo;

typedef struct s_info
{
	int	j;
	t_philo	*config;
} t_info;

int		is_blank(char c);
int		ft_atoi(char *str);
long	ft_atoi_long(char *str);
int		is_num_l(char *str);
int		parsing(int argc, char **argv, t_philo *philo);
void	create_threads(t_philo *philo);


#endif