/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:22:01 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/31 17:21:34 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//mutex: init, destroy, lock, unlock
//threads: create, join, detach
# include <pthread.h> // threads, mutex
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // usleep
# include <sys/time.h> // gettimeofday
# include <stdbool.h> // bool

struct	s_philo;
struct	s_table;

typedef struct s_philo {
	int				id;
	int				nb_of_meals_eaten;
	bool			done_eating;
	long long		timestamp_last_meal;
	struct s_table	*table;
	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	*m_right_fork;
	pthread_t		thread;
}	t_philo;

typedef struct s_table {
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals;

	bool			dead_flag;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_done_eating;
	pthread_mutex_t	m_timestamp;
}	t_table;

int			ft_init(t_table *table, char **input);
// clean up
int			ft_clean_up(t_table *table);
//helper
int			ft_atoi(const char *str);
long long	ft_timestamp(void);
int			ft_print(t_philo *philo, char *str);
int			ft_validate_input(int count, char **input);
// start
int			ft_start_procedure(t_table *table);
void		*ft_routine(void *philo_input);
void		*ft_monitor(void *table_input);
bool		read_dead_flag(t_philo *philo);

#endif
