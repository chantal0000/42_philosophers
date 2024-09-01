/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:48:18 by chbuerge          #+#    #+#             */
/*   Updated: 2024/09/01 11:20:40 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *philo_input)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)philo_input;
	if (philo->id % 2 == 0)
		usleep(philo->table->time_to_eat * 1000);
	while (read_dead_flag(philo) == false)
	{
		if (ft_eat(philo) == 1)
			return (0);
		if (ft_sleep(philo) == 1)
			return (0);
		if (ft_think(philo) == 1)
			return (0);
		i++;
	}
	return (0);
}

int	ft_start_procedure(t_table *table)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	table->start_t = ft_ts();
	if (pthread_create(&monitor, NULL, ft_monitor, table) != 0)
		return (1);
	while (i < table->nb_of_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, ft_routine,
				&table->philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < table->nb_of_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
		return (1);
	return (0);
}
