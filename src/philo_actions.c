#include "philo.h"

void take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->simulation->forks[philo->left_fork]);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(&philo->simulation->forks[philo->right_fork]);
    print_status(philo, "has taken a fork");
}

void eat(t_philo *philo)
{
    print_status(philo, "is eating");
    usleep(philo->simulation->time_to_eat * 1000);
}

void put_down_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->simulation->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork]);
}

void philo_sleep(t_philo *philo)
{
    print_status(philo, "is sleeping");
    usleep(philo->simulation->time_to_sleep * 1000);
}

void think(t_philo *philo)
{
    print_status(philo, "is thinking");
}
