/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:03:02 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/18 12:51:17 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// writes error_message in red
// and exits the program
void	ft_error_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	ft_error_free(t_table *table, t_input *input, char *error_message)
{
	int count = table->philos->input.number_of_philos;
	int i = 0;
	if (input)
		free(input);
	if (table->forks)
	{
		while ( i < count)
		{
			// pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	if(table->philos)
		free(table->philos);
	// pthread_mutex_destroy(&table->m_print);
	// pthread_mutex_destroy(&table->m_death);
	// pthread_mutex_destroy(&table->m_meal_count);
	if(table)
		free(table);
	ft_error_exit(error_message);
}
