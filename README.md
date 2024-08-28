# Philosophers Project

### Overview
The Philosophers project focuses on the basics of threading a process, exploring how to create **threads** and use **mutexes**. The task is to simulate a classic synchronization problem involving philosophers, forks, and a shared bowl of spaghetti.

### Project Requirements
Programming Language: The project must be implemented in C.
Allowed External Functions: memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
Global variables are not allowed.

### Simulation Details
A group of philosophers sit around a table with a bowl of spaghetti in the center.
Philosophers alternate between eating, thinking, and sleeping. They only perform one action at a time.
There is a fork between each pair of philosophers. To eat, a philosopher must pick up both the fork to their right and the fork to their left.
Philosophers put down their forks and start sleeping once they have finished eating. After sleeping, they think, and the cycle continues.
The simulation ends if a philosopher dies of starvation.
Philosophers do not communicate with each other and are unaware if another philosopher is about to die.

### Global Rules

The program should accept the following arguments (in this order):

`
./philo <philo_nb> <time_to_die> < time_to_eat> <time_to_sleep>  <number_of_times_each_philosopher_must_eat>
`

|  Arguments  |  Description |
| ------------ | ------------ |
| number_of_philosophers | Number of philosophers and forks. |
| time_to_die (in milliseconds)  | If a philosopher does not start eating within this time since their last meal, they die.   |
| time_to_eat (in milliseconds)  | Time a philosopher spends eating. Two forks are needed during this time.  |
|  time_to_sleep (in milliseconds)  |  Time a philosopher spends sleeping.  |
| number_of_times_each_philosopher_must_eat (optional) | The simulation ends if each philosopher has eaten this many times. If not specified, the simulation ends when a philosopher dies.|

Each philosopher is numbered from 1 to number_of_philosophers, with philosopher 1 sitting next to philosopher number_of_philosophers.

### Log Formatting
State changes for philosophers must be logged as:

- timestamp_in_ms | X has taken a fork
- timestamp_in_ms | X is eating
- timestamp_in_ms | X is sleeping
- timestamp_in_ms | X is thinking
- timestamp_in_ms | X died
*Replace timestamp_in_ms with the current timestamp in milliseconds and X with the philosopher's number.*

Logs must be consistent, with no overlap between messages. A death message should be logged within 10 ms of the philosopher's death.
