/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:43:04 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/23 18:32:02 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// PROBLEM WITH FT_DEATH funtion

// checkt eigentlich nur ob is_dead is true
// is_dead wird mit false init
//
int	ft_death_check(t_table *table)
{
	// printf("check the is_dead flag\n");
	// lock death mutex, to ensure exlusive access to the table->is_dead
	pthread_mutex_lock(&table->m_death);
	if (table->is_dead)
	{
		pthread_mutex_unlock(&table->m_death);
		return (1); // phil is dead
	}
	// ft_print("hello", table->philos);
	pthread_mutex_unlock(&table->m_death);
	return (0); // no one is dead
}
// function that finds out if a philo died
// if yes sets the flag is_dead to true
// how do find out if someone is dead?
//

// lock the meal mutex (protects last meal
	// we lock the time of the last meal and the is_eating flag
// we check if the time of the last meal eaten is >= than the time_to_die
// if they are currently eating they don't die...

int	ft_check_philo_died(t_philo *philo)
{
	long long time_since_last_meal;

	time_since_last_meal = ft_timestamp() - philo->t_last_meal;
	// printf("philo->t_last_meal %lld\n", philo->t_last_meal);
	pthread_mutex_lock(&philo->table->m_meal);
	if (time_since_last_meal >= philo->input.time_to_die && !philo->eating)
	{
		pthread_mutex_unlock(&philo->table->m_meal);
		// printf("someone died time_since_last_meal %lld\n", time_since_last_meal / 1000);
		return (1); // someone died
	}
	pthread_mutex_unlock(&philo->table->m_meal);
	return (0); //nobody died
}


int	ft_check_finished_eating(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos->input.number_of_philos)
	{
		pthread_mutex_lock(&table->m_meal);
		if (!table->philos[i].finished_eating)
		{
			pthread_mutex_unlock(&table->m_meal);
			return (0);
		}
		pthread_mutex_unlock(&table->m_meal);
		i++;
	}
	// pthread_mutex_lock(&table->m_death);
	// table->is_dead = true;
	// pthread_mutex_unlock(&table->m_death);
	return (1);
}


void	*ft_tracker(void *tracker_table)
{
	int		i;
	t_table	*table;
	//typecasting
	table = (t_table *)tracker_table;
	while (!ft_death_check(table))
	{
		// do something, if its not 1 no one died
		// inner loop goes through all phils, returns 1 if someone died
		//
		i = 0;
		while(i < table->philos->input.number_of_philos)
		{
			if (ft_check_philo_died(&table->philos[i]))
			{
				ft_print("died", &table->philos[i]);
				pthread_mutex_lock(&table->m_death);
				table->is_dead = true;
				pthread_mutex_unlock(&table->m_death);
			}
			ft_check_finished_eating(table);
			i++;
		}
	}
	// function to check for death
	return (0);
}


