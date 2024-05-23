#include "philo.h"

int main(int argc, char **argv)
{
    t_simulation simulation;

    if (argc < 5 || argc > 6)
    {
        printf("Error: Invalid number of arguments\n");
        return (1);
    }
    if (!init_simulation(&simulation, argc, argv))
    {
        printf("Error: Failed to initialize simulation\n");
        return (1);
    }
    if (!start_simulation(&simulation))
    {
        printf("Error: Failed to start simulation\n");
        return (1);
    }
    cleanup_simulation(&simulation);
    return (0);
}

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (!philo->simulation->simulation_end)
    {
        take_forks(philo);
        eat(philo);
        put_down_forks(philo);
        philo_sleep(philo);
        think(philo);
    }
    return (NULL);
}
