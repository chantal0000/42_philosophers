/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:51:24 by chbuerge          #+#    #+#             */
/*   Updated: 2024/09/01 11:26:42 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	last_philo_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->m_right_fork);
	if (ft_print(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(philo->m_right_fork);
		return (1);
	}
	pthread_mutex_lock(philo->m_left_fork);
	if (ft_print(philo, "has taken a fork") == 1)
	{
		unlock_double_mutex(philo->m_right_fork, philo->m_left_fork);
		return (1);
	}
	if (ft_print(philo, "is eating") == 1)
	{
		unlock_double_mutex(philo->m_right_fork, philo->m_left_fork);
		return (1);
	}
	set_timestamp(philo);
	usleep(philo->table->time_to_eat * 1000);
	unlock_double_mutex(philo->m_right_fork, philo->m_left_fork);
	return (0);
}

int	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->m_left_fork);
	if (ft_print(philo, "has taken a fork") == 1
		|| philo->table->nb_of_philos == 1)
	{
		pthread_mutex_unlock(philo->m_left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->m_right_fork);
	if (ft_print(philo, "has taken a fork") == 1)
	{
		unlock_double_mutex(philo->m_left_fork, philo->m_right_fork);
		return (1);
	}
	if (ft_print(philo, "is eating") == 1)
	{
		unlock_double_mutex(philo->m_left_fork, philo->m_right_fork);
		return (1);
	}
	set_timestamp(philo);
	usleep(philo->table->time_to_eat * 1000);
	unlock_double_mutex(philo->m_left_fork, philo->m_right_fork);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (philo->id == philo->table->nb_of_philos && philo->id != 1)
	{
		if (last_philo_eats(philo) == 1)
			return (1);
	}
	else
	{
		if (philo_eats(philo) == 1)
			return (1);
	}
	philo->nb_of_meals_eaten++;
	if (philo->nb_of_meals_eaten == philo->table->nb_of_meals)
	{
		pthread_mutex_lock(&philo->table->m_done_eating);
		philo->done_eating = true;
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
		usleep(1000);
		return (0);
	}
	return (1);
}
