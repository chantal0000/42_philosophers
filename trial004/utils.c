#include "philo.h"

int ft_clean_up(t_table *table)
{
    int i;

    i = 0;
    while (i < table->nb_of_philos)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&table->m_print);
    pthread_mutex_destroy(&table->m_dead);
    pthread_mutex_destroy(&table->m_meal);
    free(table->forks);
    free(table->philos);
    return (0);
}

// ft get timestamp function
// convert the time from fct into miliseconds
// combines seconds and microseconds into single value (ms)
long long	ft_timestamp(void)
{
	long long		timestamp_ms;
	struct timeval	current_time;

	timestamp_ms = 0;
	if (!gettimeofday(&current_time, NULL))
		timestamp_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (timestamp_ms);
}


