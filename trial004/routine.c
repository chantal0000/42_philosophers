/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:51:24 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/31 13:06:38 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// routine

// start the threads?
// group A should wait x amount of time to avoid deadlock


// while (!no philosopher has died)
// {
// eat
    // (try) to grab forks
    // usleep for amount of time eating takes

// sleep
    // usleep for time_to_sleep

// think
    // for the calculated time
// }
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
int	ft_eat(t_philo *philo)
{
	//printf("ft_eat\n");
	pthread_mutex_lock(philo->m_left_fork);
	// usleep(100);
	if (ft_print(philo, "takes fork left") == 1)
	{
		pthread_mutex_unlock(philo->m_left_fork);
		return (1);
	}
	if (philo->table->nb_of_philos == 1)
	{
		pthread_mutex_unlock(philo->m_left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->m_right_fork);
	if (ft_print(philo, "takes fork right") == 1)
	{
		pthread_mutex_unlock(philo->m_left_fork);
		pthread_mutex_unlock(philo->m_right_fork);
		return (1);
	}
	if (ft_print(philo, "is eating") == 1)
	{
		pthread_mutex_unlock(philo->m_left_fork);
		pthread_mutex_unlock(philo->m_right_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->table->m_timestamp);
	philo->timestamp_last_meal = ft_timestamp();
	pthread_mutex_unlock(&philo->table->m_timestamp);
	usleep(philo->table->time_to_eat * 1000);

	pthread_mutex_unlock(philo->m_left_fork);
	// printf("philo %d release left fork\n", philo->id);
	pthread_mutex_unlock(philo->m_right_fork);
	// printf("philo %d release right fork\n", philo->id);
	// finished eating, put down timestamp()
	// printf("timestamp_last_meal %lld\n", philo->timestamp_last_meal);
	// done_eating true
	// finished eating, count meal
	philo->nb_of_meals_eaten++;
	// printf("philo %d has eaten %d times\n", philo->id, philo->nb_of_meals_eaten);
	if (philo->nb_of_meals_eaten == philo->table->nb_of_meals)
	{
		pthread_mutex_lock(&philo->table->m_done_eating);
		philo->done_eating = true; // philo is full
		pthread_mutex_unlock(&philo->table->m_done_eating);
		return (1);
	}
	return (0);
}
int	ft_sleep(t_philo *philo)
{
	// printf("philo %d is sleeping\n", philo->id);

	if (ft_print(philo, "is sleeping") == 1)
		return (1);
	usleep(philo->table->time_to_sleep * 1000);
	return (0);
}

int	ft_think(t_philo *philo)
{
	// printf("philo %d is thinking\n", philo->id);
	if(read_dead_flag(philo) == false)
	{
		ft_print(philo, "is thinking");
		return (0);
	}
	return (1);
}

void	*ft_routine(void *philo_input)
{
	t_philo *philo;
	int i = 0;
	// make one group wait to join table
	philo = (t_philo *)philo_input;
	if (philo->id % 2 == 0)
		usleep(1000);
	// printf("\nft_routine, philo id %d\n\n", philo->id);
	// while loop
	// philo->timestamp_last_meal = ft_timestamp();
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

