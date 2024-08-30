/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:48:18 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/30 13:18:23 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"



int	ft_start_procedure(t_table *table)
{
	int			i;
	pthread_t	monitor;

	i = 0;
//save the time of the start?
	table->start_time = ft_timestamp();
	// printf("start time %lld\n", table->start_time);
	// create thread for tracker
	if (pthread_create(&monitor, NULL, ft_monitor, table) != 0)
		return (1);
	// create thread for philos
	while (i < table->nb_of_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, ft_routine, &table->philos[i]) != 0)
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
