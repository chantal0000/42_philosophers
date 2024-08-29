/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:22:01 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/23 16:38:12 by chbuerge         ###   ########.fr       */
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
# include <stdbool.h> // bool

struct s_philo;
struct t_table;

typedef struct s_input {

} t_input;

typedef struct s_philo {
	int				id;
	int				nb_of_meals_eaten;
	bool			eating;
	bool			done_eating;

	long long			time_since_last_meal; // init to what
	struct s_table	*table; // reference to table data


	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	*m_right_fork;

	pthread_t		thread;

	// pthread_mutex_t	*mutex_number_meals_eaten;
	// pthread_mutex_t	*mutex_last_time_eating;
	// timestamp??
	// flag if the philo is dead?
	// flag if philo is full (optional)
	// last timestamp phil ate

	// ...
} t_philo;

typedef struct s_table {
// input / argv
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_meals; // number of meals a philosopher must eat until full, OPT. ARGV

	bool		dead_flag; // false if no philo is dead, true if philo is dead
	long long	start_time;


////

	t_philo		*philos;
	// pthread_t	*threads_phil;
	// mutex for shared ressources
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print; // protects who can write
	pthread_mutex_t	m_dead; // protects is_dead flag
	pthread_mutex_t	m_meal; // protects

} t_table;

// check if the input is valid

// init all

int ft_init(t_table *table, char **input);

// clean up
int ft_clean_up(t_table *table);

//helper
int	ft_atoi(const char *str);

#endif
