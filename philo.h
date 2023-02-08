/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:21:43 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/08 17:38:21 by hkahsay          ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				last_meal;
	pthread_t		tid;
	int				next;		
	int				pos;
	int				philo_id;
	int				free;
	int				n_meals;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	int				nbr_of_philosophers;
	int				nb_of_meals;
	int				philo_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				stop;
	int				meals;
	t_philo			*philo;
	long int		time_to_start;
	int				dead;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	status;

}					t_info;

int				is_blank(char c);
int				ft_atoi(char *str);
long			ft_atoi_long(char *str);
int				is_num_l(char *str);
int				parsing(int argc, char **argv, t_info *info);
int				create_threads(t_info *info);
long long		get_time_in_ms(void);
struct s_info	*set_philos(t_info	*info);
void			ft_usleep(int m_sec);
int				is_dead(t_info	*info);
void			take_fork(t_philo *philo);
void			eat_philo(t_philo	*philo);



#endif