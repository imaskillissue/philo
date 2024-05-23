# Task
There is one fork between each pair of philosophers. Therefore
    - if there are several
philosophers
    - each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher
    - there should be only one fork on the table
# Rules
* Allowed extern functions:
    - memset
    - printf
    - malloc
    - free
    - write
    - usleep
    - gettimeofday
    - pthread_create
    - pthread_detach
    - pthread_join
    - pthread_mutex_init
    - pthread_mutex_destroy
    - pthread_mutex_lock
    - pthread_mutex_unlock
* No Global Variables
* The Arguments of the programm are:
    - number of philosophers
    - time to die
    - time to sleep
    - (number of times a each need to eat)
* Each philo has a number from 1 - number_of_philos
* Philo number 1 sits next to 2 and number_of_philos
* The messages formated like this X is to replace with the number of the philo and timestamp_in_ms with the current timestamp:
    - timestamp_in_ms X has taken a fork
    - timestamp_in_ms X is eating
    - timestamp_in_ms X is sleeping
    - timestamp_in_ms X is thinking
    - timestamp_in_ms X died
* A displayed state message should not be mixed up with another message.
* A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.
* philos should avoid dying
* To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.
* Should be written only in C