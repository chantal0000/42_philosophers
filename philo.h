/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:06:10 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/02 15:19:03 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h> //threads
#include <stdlib.h> // exit
#include <sys/time.h> // timestamp


// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]
// example: 5 800 200 200 [5]

typedef struct s_data t_data;


// structure of each philosopher
typedef struct s_philo
{
	t_data		*data;
	int			id;
	//
	int			id_ate;
	long long	last_meal;
	pthread_t	thread_id;
	int			left_fork;
	int			right_fork;
} t_philo;

// overall structure that holds all the philosophers
struct s_data
{
	// data from input
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			times_must_eat;
	//
	long long		first_timestamp;
	pthread_mutex_t	*fork;
	pthread_mutex_t	meal;
	pthread_mutex_t	dead;
	int				died;
	//
	t_philo			*philos; // array to all philosophers


};

// fork = mutex


int	ft_init(t_data *data, char **input);

int	ft_atoi(const char *str);
void	ft_error_exit(char *error_message);


int		ft_validate_input(int count, char **input);
