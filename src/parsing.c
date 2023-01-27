#include"../philo.h"

int	parsing(int argc, char **argv, t_philo *philo)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep =  ft_atoi(argv[4]);
	philo->number_of_meals = ft_atoi[argv[5]];
}