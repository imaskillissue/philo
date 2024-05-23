#include "philo.h"
#include <stdlib.h>

static void init_philos(t_simulation *simulation)
{
    int i;

    simulation->philosophers = malloc(sizeof(t_philo) * simulation->number_of_philosophers);
    if (!simulation->philosophers)
        return ;
    i = 0;
    while (i < simulation->number_of_philosophers)
    {
        simulation->philosophers[i].id = i + 1;
        simulation->philosophers[i].left_fork = i;
        simulation->philosophers[i].right_fork = (i + 1) % simulation->number_of_philosophers;
        simulation->philosophers[i].simulation = simulation;
        i++;
    }
}

static void init_simulation_settings(t_simulation *simulation, int argc, char **argv)
{
    simulation->number_of_philosophers = atoi(argv[1]);
    simulation->time_to_die = atoi(argv[2]);
    simulation->time_to_eat = atoi(argv[3]);
    simulation->time_to_sleep = atoi(argv[4]);
    if (argc == 6)
        simulation->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
    else
        simulation->number_of_times_each_philosopher_must_eat = -1;
    simulation->simulation_end = false;
}

bool init_simulation(t_simulation *simulation, int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        return (false);
    init_simulation_settings(simulation, argc, argv);
    init_philos(simulation);
    if (!simulation->philosophers)
        return (false);
    init_mutexes(simulation);
    return (true);
}
