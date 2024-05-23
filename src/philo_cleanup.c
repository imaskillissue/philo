#include "philo.h"
#include <stdlib.h>

void cleanup_simulation(t_simulation *simulation)
{
    int i;

    if (simulation->philosophers)
    {
        for (i = 0; i < simulation->number_of_philosophers; i++)
        {
            pthread_join(simulation->philosophers[i].thread, NULL);
        }
        free(simulation->philosophers);
    }
    if (simulation->forks)
    {
        destroy_mutexes(simulation);
        free(simulation->forks);
    }
}
