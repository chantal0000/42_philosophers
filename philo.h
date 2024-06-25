/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:06:10 by chbuerge          #+#    #+#             */
/*   Updated: 2024/06/25 15:41:13 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h> //threads
#include <stdlib.h> // exit


// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]
// example: 5 800 200 200 [5]

typedef struct s_data t_data;

typedef struct s_fork
{
	int	fork_id;
	pthread_mutex_t fork;
}	t_fork;

// structure of each philosopher
typedef struct s_philo
{
	int		id;
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_data	*data;
} t_philo;

// overall structure that holds all the philosophers
struct s_data
{
	int		philo_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	times_must_eat;
	int		simulation_end; // full or death
	t_philo	*philos; // array to all philosophers
	t_fork	*forks; // array to all the forks/ mutexes
};

// fork = mutex





void	ft_error_exit(char *error_message);

int		ft_validate_input(int count, char **input);
