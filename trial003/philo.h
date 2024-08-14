/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:22:01 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/14 13:04:00 by chbuerge         ###   ########.fr       */
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




typedef struct s_input {
	int	number_of_philos;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	num_of_meals;
	// timestamp start of program
	// ..
} t_input;

typedef struct s_philo {
	t_input			input;
	int				philo_id;
	pthread_mutex_t	*mutex_left_fork;
	pthread_mutex_t	*mutex_right_fork;
	pthread_mutex_t	*mutex_number_meals_eaten;
	pthread_mutex_t	*mutex_last_time_eating;
	// timestamp??
	// flag if the philo is dead?
	// flag if philo is full (optional)
	// last timestamp phil ate

	// ...
} t_philo;

typedef struct s_table {
	t_philo	**philos;
	pthread_mutex_t	*forks;
	pthread_t		*threads_phil;
	long long	start_time;
	// ... mutex here?
} t_table;

int	ft_atoi(const char *str);
t_philo	**ft_init_philo(t_input input);

#endif
