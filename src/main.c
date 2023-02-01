#include"../philo.h"

int main(int argc, char *argv[])
{
    t_philo * philo = malloc(sizeof(t_philo));
    parsing(argc, argv, philo);
    create_threads(philo);
    return 0;
}