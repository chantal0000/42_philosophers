
#include "philo.h"

// initialize the table overall structure


// init all philos


// OR wait do we init the threads in routine, when we get started?
// init threads
    // monitor
    // all philos


// init mutexes

int    ft_init_mutexes(t_table *table)
{
    if (pthread_mutex_init(&(table->m_print), NULL) != 0)
        return (1);
    if (pthread_mutex_init(&(table->m_dead), NULL) != 0)
        return (1);
    if (pthread_mutex_init(&(table->m_done_eating), NULL) != 0)
        return (1);
    if (pthread_mutex_init(&(table->m_timestamp), NULL) != 0)
		return (1);
    return (0);
}


    // init forks

int ft_init_philos(t_table *table)
{
    int i;

    i = 0;
    while (i < table->nb_of_philos)
    {
        table->philos[i].id = i + 1;
        table->philos[i].nb_of_meals_eaten = 0;
        // table->philos[i].eating = false;
        table->philos[i].done_eating = false;
        table->philos[i].timestamp_last_meal = ft_timestamp(); // init to what??
        table->philos[i].table = table;
        table->philos[i].m_left_fork = &table->forks[i];
        table->philos[i].m_right_fork = &table->forks[(i + 1) % table->nb_of_philos];
        // bei 4 philo für letzen philo
        // 3 + 1 % 4 = forks[0]

        // wann init threads?
        i++;
    }
    return (0); // unnötig weil es keinen fail case gibt?
}

int ft_init(t_table *table, char **input)
{
    table->nb_of_philos = ft_atoi(input[1]);
    table->time_to_die = ft_atoi(input[2]);
    table->time_to_eat = ft_atoi(input[3]);
    table->time_to_sleep = ft_atoi(input[4]);
    table->nb_of_meals = -1;
    if (input[5])
        table->nb_of_meals = ft_atoi(input[5]);
    table->dead_flag = false;
    table->start_time = 0;
    table->philos = malloc(sizeof(t_philo) * table->nb_of_philos);
    if(!table->philos)
        return (1); // error handling in main
    /// init forks, as many as philos
    int i = 0;
    table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_of_philos);
    if (!table->forks)
        return (1); // if this is an extra function handle differently so you return to main
    while (i < table->nb_of_philos)
    {
        if (pthread_mutex_init(&table->forks[i], NULL) != 0)
        {
            return (1); // if this is an extra function handle differently so you return to main
        }
        i++;
    }
    ////
    //// init philos
    if (ft_init_philos(table) == 1)
        return (1);
    // init other mutexes than forks
    if (ft_init_mutexes(table) == 1)
        return (1);
    return (0);
}
