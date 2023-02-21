/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:21:43 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/21 16:17:45 by hkahsay          ###   ########.fr       */
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
# define WHITE   "\033[1;37m"

typedef struct s_philo
{
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	int				last_meal;
	pthread_t		tid;
	int				philo_id;
	int				meal_counter;
	int				dead;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	int				nbr_of_philosophers;
	int				philo_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				stop;
	pthread_t		tid_dead;
	int				nb_of_meals;
	int				meals;
	t_philo			*philo;
	long int		end;
	long int		time_to_start;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	status;

}					t_info;

//--------utils----------
int				is_blank(char c);
int				ft_atoi(char *str);
long			ft_atoi_long(char *str);
int				is_num_l(char *str);
int				parsing(int argc, char **argv, t_info *info);
//--------setting time---------
long int		actual_time_msec(void);
void			ms_sleep(int m_sec);
long int		elapsed_time(t_info *info);
//------------print or display status--------
void			display_status(long int t_ms, t_philo *philo, char *str);
//---------init data and philos---------
int				create_threads(t_info *info);
struct s_info	*set_philos(t_info	*info);
//---------philo routine----------
int				take_fork(t_philo *philo);
// int				all_philo_eat(t_philo *philo);
void			eat_philo(t_philo	*philo);
//---------check if philo is dead-----
void			*check_dead(void	*args);
void			one_philo(t_philo *philo);
// void			check_philo_eat_enough(t_info *info);
void			philo_death_check(t_info *info);
void			philo_sleep(t_philo *philo);

#endif
