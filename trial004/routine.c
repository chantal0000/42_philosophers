/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:51:24 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/31 13:33:39 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->m_left_fork);
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
	pthread_mutex_unlock(philo->m_right_fork);
	philo->nb_of_meals_eaten++;
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
	if (ft_print(philo, "is sleeping") == 1)
		return (1);
	usleep(philo->table->time_to_sleep * 1000);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if (read_dead_flag(philo) == false)
	{
		ft_print(philo, "is thinking");
		return (0);
	}
	return (1);
}

void	*ft_routine(void *philo_input)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)philo_input;
	if (philo->id % 2 == 0)
		usleep(1000);
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

