/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:22:01 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/09 17:57:37 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_table {
	t_philo *philos;
	pthread_mutex_t *forks;
	// ...
} t_table;

typedef struct s_input {
	int	number_of_philos;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	// ..
} t_input;

typedef struct s_philo {
	t_input			input;
	int				philo_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	// ...
} t_philo;


#endif
