#include "philo.h"

static void join_philo_threads(t_simulation *simulation, int num_philos)
{
    int i;

    i = 0;
    while (i < num_philos)
    {
        pthread_join(simulation->philosophers[i].thread, NULL);
        i++;
    }
}

static void create_philo_threads(t_simulation *simulation)
{
    int i;

    i = 0;
    while (i < simulation->number_of_philosophers)
    {
        if (pthread_create(&simulation->philosophers[i].thread, NULL, &philo_routine, &simulation->philosophers[i]) != 0)
        {
            simulation->simulation_end = true;
            break;
        }
        i++;
    }
}

bool start_simulation(t_simulation *simulation)
{
    if (simulation == NULL || simulation->philosophers == NULL)
        return (false);
    create_philo_threads(simulation);
    if (simulation->simulation_end)
        return (false);
    join_philo_threads(simulation, simulation->number_of_philosophers);
    return (true);
}
