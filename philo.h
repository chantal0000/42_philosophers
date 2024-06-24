/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:06:10 by chbuerge          #+#    #+#             */
/*   Updated: 2024/06/24 15:46:25 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> // exit

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
	int	philo_num;
	long	timr_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	t_philo	*philos; // array to all philosophers
	t_fork	*forks; // array to all the forks/ mutexes
};

// fork = mutex





void	ft_error_exit(char *error_message);

int		ft_validate_input(int count, char **input);
