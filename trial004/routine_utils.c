/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:54:50 by chbuerge          #+#    #+#             */
/*   Updated: 2024/09/01 11:20:19 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_double_mutex(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2)
{
	pthread_mutex_unlock(mutex1);
	pthread_mutex_unlock(mutex2);
}

void	set_timestamp(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->m_timestamp);
	philo->timestamp_last_meal = ft_ts();
	pthread_mutex_unlock(&philo->table->m_timestamp);
}
