#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>

typedef struct s_philo
{
    int id;
    pthread_t thread;
    int left_fork;
    int right_fork;
    struct s_simulation *simulation;
}               t_philo;

typedef struct s_simulation
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    bool simulation_end;
    pthread_mutex_t *forks;
    pthread_mutex_t writing;
    pthread_mutex_t death;
    t_philo *philosophers;
    struct timeval start_time;
}               t_simulation;

// Philosopher actions
void take_forks(t_philo *philo);
void eat(t_philo *philo);
void put_down_forks(t_philo *philo);
void philo_sleep(t_philo *philo);
void think(t_philo *philo);

// Mutex management
void init_mutexes(t_simulation *simulation);
void destroy_mutexes(t_simulation *simulation);

#endif
