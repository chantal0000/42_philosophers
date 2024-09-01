/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:06:03 by chbuerge          #+#    #+#             */
/*   Updated: 2024/09/01 11:26:18 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(t_table *table, int i)
{
	pthread_mutex_lock(&table->m_print);
	printf("%lld %i died\n", ft_ts() - table->start_t, table->philos[i].id);
	pthread_mutex_unlock(&table->m_print);
}

int	philo_finished_eating(t_table *table)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < table->nb_of_philos)
	{
		pthread_mutex_lock(&table->m_done_eating);
		if (table->philos[i].done_eating == true)
		{
			count++;
		}
		pthread_mutex_unlock(&table->m_done_eating);
		i++;
	}
	if (count == table->nb_of_philos)
		return (1);
	usleep(1000);
	return (0);
}

int	ft_check_for_death(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->table->m_timestamp);
	time = ft_ts() - philo->timestamp_last_meal;
	pthread_mutex_unlock(&philo->table->m_timestamp);
	if (time > philo->table->time_to_die)
		return (1);
	return (0);
}

void	*ft_monitor(void *table_input)
{
	t_table	*table;
	int		i;

	table = (t_table *)table_input;
	while (read_dead_flag(&table->philos[0]) == false)
	{
		i = -1;
		while (++i < table->nb_of_philos)
		{
			if (ft_check_for_death(&(table->philos[i])) == 1
				&& (table->philos[i].done_eating == false))
			{
				pthread_mutex_lock(&table->m_dead);
				table->dead_flag = true;
				pthread_mutex_unlock(&table->m_dead);
				print_death(table, i);
				return (0);
			}
		}
		if (philo_finished_eating(table) == 1)
			return (0);
	}
	return (0);
}
