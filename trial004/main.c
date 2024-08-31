/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:23:11 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/31 13:21:12 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (ft_validate_input(argc, argv) != 0)
	{
		printf("invalid input!\n enter: [nb_of_philo] [time_to_die] \
		 [time_to_eat] [time_to_sleep]\n \
		 optional: [nb_of_times_each_philo_must_eat]\n");
		return (1);
	}
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (ft_init(table, argv) != 0)
	{
		free(table);
		return (1);
	}
	ft_start_procedure(table);
	ft_clean_up(table);
	return (0);
}
