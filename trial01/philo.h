/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:29:08 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/09 12:50:29 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h> //threads
#include <stdlib.h> // exit
#include <sys/time.h> // timestamp


typedef struct s_phil
{
	// 1. unique identifier for each phil
	int	id;
	// 2. number of the meals that were eaten
	int	meals_eaten;
	// 3. timestamp of phils last meal
	int	last_meal;
	// 4. time in milisecond phil will tie if they havent eaten
	int	time_to_die;
	// 5. time in miliseconds phil should sleep between meals
	int	time_to_sleep;
	// 6. time in milisecond phil spends eating
	int	time_to_eat;
	// 7. timestamp when simulation started
	int	start_time;
	// 8. total num of phils
	int	num_of_phil;
	// 9. num of imes each phil needs to eat (optional input?)
	int	num_times_to_eat;
	// 10. pointer to shared flag indicating if phil died
	int	*dead;
	// 11.
	pthread_t	thread_id;
	// 12. pointer to the mutex representing phils left fork
	pthread_mutex_t	*left_fork;
	// 13.
	pthread_mutex_t	*left_right;
	// 14. pointer for output sync
	pthread_mutex_t	*write_lock;
	// 15. mutex for dead flag
	pthread_mutex_t	*dead_lock;
	// 16.
	pthread_mutex_t	*meal_lock;
} t_phil;

typedef struct s_data
{
	// 1. indicating flag if phil died
	int	dead_flag;
	// 2. mutex for dead_flag
	pthread_mutex_t	dead_lock;
	// 3.
	pthread_mutex_t	meal_lock;
	// 4.
	pthread_mutex_t	write_lock;
	// 5.
	t_phil *phil;
} t_data;





void	ft_error_exit(char *error_message);
int		ft_validate_input(int count, char **input);
#endif
