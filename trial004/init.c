/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:24:25 by chbuerge          #+#    #+#             */
/*   Updated: 2024/09/01 11:20:40 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutexes(t_table *table)
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

int	ft_init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].nb_of_meals_eaten = 0;
		table->philos[i].done_eating = false;
		table->philos[i].timestamp_last_meal = ft_ts();
		table->philos[i].table = table;
		table->philos[i].m_left_fork = &table->forks[i];
		table->philos[i].m_right_fork = &table->forks[(i + 1)
			% table->nb_of_philos];
		i++;
	}
	return (0);
}

void	ft_init_input(t_table *table, char **input)
{
	table->nb_of_philos = ft_atoi(input[1]);
	table->time_to_die = ft_atoi(input[2]);
	table->time_to_eat = ft_atoi(input[3]);
	table->time_to_sleep = ft_atoi(input[4]);
	table->nb_of_meals = -1;
	if (input[5])
		table->nb_of_meals = ft_atoi(input[5]);
}

int	ft_init(t_table *table, char **input)
{
	int	i;

	ft_init_input(table, input);
	table->dead_flag = false;
	table->start_t = 0;
	table->philos = malloc(sizeof(t_philo) * table->nb_of_philos);
	if (!table->philos)
		return (1);
	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_of_philos);
	if (!table->forks)
		return (1);
	while (i < table->nb_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (ft_init_philos(table) == 1)
		return (1);
	if (ft_init_mutexes(table) == 1)
		return (1);
	return (0);
}
