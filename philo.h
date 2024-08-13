/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:22:01 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/13 14:50:26 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//mutex: init, destroy, lock, unlock
//threads: create, join, detach
#include <pthread.h> // threads, mutex
#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <unistd.h> // usleep
#include <sys/time.h> // gettimeofday

struct s_philo;

typedef struct s_table {
	struct s_philo *philos;
	pthread_mutex_t *forks;
	// ...
} t_table;

typedef struct s_input {
	int	number_of_philos;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	// timestamp start of program
	// ..
} t_input;

typedef struct s_philo {
	t_input			input;
	int				philo_id;
	pthread_mutex_t	*mutex_left_fork;
	pthread_mutex_t	*mutex_right_fork;
	pthread_mutex_t	*mutex_number_meals_eaten;
	pthread_mutex_t	*mutex_last_time_eating
	// timestamp??
	// flag if the philo is dead?
	// flag if philo is full (optional)
	// last timestamp phil ate

	// ...
} t_philo;


#endif
