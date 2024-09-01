/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:21:56 by chbuerge          #+#    #+#             */
/*   Updated: 2024/09/01 11:20:40 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clean_up(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->m_print);
	pthread_mutex_destroy(&table->m_dead);
	pthread_mutex_destroy(&table->m_done_eating);
	pthread_mutex_destroy(&table->m_timestamp);
	free(table->forks);
	free(table->philos);
	free(table);
	return (0);
}

// ft get timestamp function
// convert the time from fct into miliseconds
// combines seconds and microseconds into single value (ms)
// time in MILLISECONDS
// current_time.tv_sec -> number of seconds since UNIX epoch (jan, 01, 1970)
// current_time.tv_usec -> microseconds part of current time
// * 1000 convert seconds into ms
// / 1000 convert microsecond part to miliseconds
long long	ft_ts(void)
{
	long long		timestamp_ms;
	struct timeval	current_time;

	timestamp_ms = 0;
	if (!gettimeofday(&current_time, NULL))
	{
		timestamp_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	}
	return (timestamp_ms);
}

int	ft_print(t_philo *philo, char *str)
{
	t_table		*table;
	long long	time;

	table = philo->table;
	time = ft_ts() - table->start_t;
	if (read_dead_flag(&table->philos[0]) == false)
	{
		pthread_mutex_lock(&table->m_print);
		printf("%lld %d %s\n", time, philo->id, str);
		pthread_mutex_unlock(&table->m_print);
		return (0);
	}
	return (1);
}

bool	read_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->m_dead);
	if (philo->table->dead_flag == false)
	{
		pthread_mutex_unlock(&philo->table->m_dead);
		return (false);
	}
	pthread_mutex_unlock(&philo->table->m_dead);
	return (true);
}
