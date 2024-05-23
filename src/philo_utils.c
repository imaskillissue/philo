#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Utility function to get the current time in milliseconds
unsigned long get_time(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

// Utility function to print status with timestamp
void print_status(t_philo *philo, char *status)
{
    unsigned long time;

    pthread_mutex_lock(&philo->simulation->writing);
    if (!philo->simulation->simulation_end)
    {
        time = get_time() - philo->simulation->start_time.tv_sec * 1000;
        printf("%lums %d %s\n", time, philo->id, status);
    }
    pthread_mutex_unlock(&philo->simulation->writing);
}

// Utility function to parse simulation arguments
int parse_arguments(int argc, char **argv, t_simulation *simulation)
{
    if (argc < 5 || argc > 6)
        return (0);
    simulation->number_of_philosophers = atoi(argv[1]);
    simulation->time_to_die = atoi(argv[2]);
    simulation->time_to_eat = atoi(argv[3]);
    simulation->time_to_sleep = atoi(argv[4]);
    if (argc == 6)
        simulation->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
    else
        simulation->number_of_times_each_philosopher_must_eat = -1;
    return (1);
}
