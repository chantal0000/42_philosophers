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
	//t_input			input;
	int				meals_eaten;
	bool			eating;
	bool			finished_eating;
	long long			t_last_meal;
	int				philo_id;
	pthread_t		thread;
	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	*m_right_fork;
	struct s_table	*table; // reference to table data
	// pthread_mutex_t	*mutex_number_meals_eaten;
	// pthread_mutex_t	*mutex_last_time_eating;
	// timestamp??
	// flag if the philo is dead?
	// flag if philo is full (optional)
	// last timestamp phil ate

	// ...
} t_philo;

typedef struct s_table {
	t_philo		*philos;
	long long	start_time;
	bool		is_dead;
	// pthread_t	*threads_phil;
	// mutex for shared ressources
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print; // protects who can write
	pthread_mutex_t	m_death; // protects is_dead flag
	pthread_mutex_t	m_meal; // protects
	int	number_of_philos;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	num_of_meals;

} t_table;

// check if the input is valid

// init all
t_input		*ft_init_input(char **arg);
void 		ft_init_philo(t_input input, t_table *table);
void		ft_init_forks(t_table *table);
t_table		*ft_init(t_input input);

int			ft_atoi(const char *str);
void		ft_error_exit(char *error_message);
void		ft_error_free(t_table *table, t_input *input, char *error_message);
int			ft_validate_input(int count, char **input);
// void	ft_tracker(void *tracker_table);
int			ft_start_procedure(t_table *table);
long long	ft_timestamp(void);
int			ft_death_check(t_table *table);
int			ft_usleep(long long time);
void	ft_print(char *str, t_philo *philo);
void	*ft_tracker(void *tracker_table);
#endif
