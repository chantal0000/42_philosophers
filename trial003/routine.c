/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:09:17 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/23 18:40:19 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// is_sleeping()
// is_thinking()
// is_eating()
// Fork Management

// grab_forks()
// Thread Routine

// routine()
// Synchronization Checks

// death_check()
// print_status()
// ft_usleep()
// get_timestamp()
#include "philo.h"
/////////////////////////////////////////////////




// SLEEP
void	ft_sleep(t_philo *philo)
{
	// print that you are sleeping
	// printf("ft_sleep\n\n");
	ft_print("is sleeping", philo);
	ft_usleep(philo->input.time_to_sleep);
	// sleep for as long as you should
	// ft_usleep(philo->input.time_to_sleep);
}

// // THINKING
void	ft_think(t_philo *philo)
{
	//print thinking
	int t;
	
	ft_print("is thinking", philo);
	//sleep for as long as you thinking
	t = philo->input.time_to_die - philo->input.time_to_eat - philo->input.time_to_sleep;
	if (!ft_death_check(philo->table))
	{
		if((philo->input.number_of_philos % 2) == 0)
			usleep(10);
		else
		{
			if (t <= 0)
				usleep(900);
			else
				usleep(t * 900);
		}
	}
}



int	ft_grab_forks(t_philo *philo)
{
	// pthread_mutex_lock(philo->m_left_fork);
	// ft_print("philo has taken a fork", philo);
	// // !! handle only one philo
	// pthread_mutex_lock(philo->m_right_fork);
	// ft_print("philo has taken a fork", philo);
	// return (0);
	if (philo->philo_id % 2 == 0)
	{
		// printf("Philo %d attempting to lock left fork\n", philo->philo_id);
		pthread_mutex_lock(philo->m_left_fork);
		// ft_print("has taken a fork", philo);
	}
	else
		pthread_mutex_lock(philo->m_right_fork);
	ft_print("has taken a fork", philo);
	// if (philo->input.number_of_philos == 1)
	// {
	// 	ft_usleep(philo->input.time_to_die);
	// 	pthread_mutex_unlock(philo->m_right_fork);
	// 	return (0);
	// }
	if (philo->philo_id % 2 == 0)
	 	pthread_mutex_lock(philo->m_right_fork);
	else
		pthread_mutex_lock(philo->m_left_fork);
	 ft_print("has taken a fork", philo);
	return (1);
}
// EAT
void	ft_eat(t_philo *philo)
{
	// check if
	// death_check -> no philo is dead
	// ??? grab forks ??? function
	// grab function returns xx for 1 phil, otherwise zz
	// ADD condition so we dont go here if we only have one phil
	while (!ft_death_check(philo->table) && ft_grab_forks(philo))
	{

	// print status -> function has own mutex?
	// print is eating
		ft_print("is eating", philo);
	// lock meal mutex
		pthread_mutex_lock(&philo->table->m_meal);
	// set time of last meal to timestamp
		philo->t_last_meal = ft_timestamp();
	// add +1 to meal eaten
		philo->meals_eaten += 1;
	// is eating = true
		philo->eating = true;
	// unlock meal mutex
		pthread_mutex_unlock(&philo->table->m_meal);
	// !!!!put to sleep for the time of eating!!!!
		ft_usleep(philo->input.time_to_eat);
	// lock meal mutex
		pthread_mutex_lock(&philo->table->m_meal);
	// set is eating to false
		philo->eating = false;
	// if num of meals is not -1 and the meals eaten are >= to the meals they should eat
	if (philo->input.num_of_meals != -1 && philo->meals_eaten >= philo->input.num_of_meals)
		philo->finished_eating = true;
	// set finished_eating to true
	// unlock:
	// meal
	pthread_mutex_unlock(&philo->table->m_meal);
	// // !!!r_fork
	pthread_mutex_unlock(philo->m_right_fork);
	// !!!l_fork
	pthread_mutex_unlock(philo->m_left_fork);
	}
}



// functions being called by the philos threads
// handle eating, sleeping, thinking

void *ft_routine(void *phil_philos)
{
	t_philo *philos;
	t_table *table;

	philos = (t_philo *)phil_philos;
	table = philos->table;
	// handle groups to sleep -> avoid deadlock
	// loops until death_check returns 1
	if (philos->philo_id % 2 != 0)
    {
        ft_usleep(100);  // Adjust the delay as needed (in microseconds)
    }
	while(!ft_death_check(table))
	{
        ft_eat(philos);
        printf("Philosopher %d is now going to sleep\n", philos->philo_id);
		ft_print("Test\n", philos);
        ft_sleep(philos);
        printf("Philosopher %d is now thinking\n", philos->philo_id);
        ft_think(philos);
	}
	return (phil_philos); // return what here?
}


/////////////////////////////////////////////////

// starting point of simulation: / start_dinner

int	ft_start_procedure(t_table *table)
{
	int			i;
	pthread_t	tracker_thread;

	i = 0;
	// set starting time
	table->start_time = ft_timestamp();
	// create thread tracker, to track the other threads
	if (pthread_create(&tracker_thread, NULL, &ft_tracker, (void *)table) != 0)
		ft_error_free(table, &table->philos->input, "thread creation tracker failed\n");
	// create threads for all philos
	while (i < table->philos->input.number_of_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, ft_routine, &table->philos[i]) != 0)
			ft_error_free(table, &table->philos->input, "thread creation philos failed\n");
		i++;
	}
	i = 0;
	while (i < table->philos->input.number_of_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			ft_error_free(table, &table->philos->input, "thread philos join failed\n");
		i++;
	}
	if (pthread_join(tracker_thread, NULL) != 0)
			ft_error_free(table, &table->philos->input, "thread tracker join failed\n");
	return (0);
}



// save time
// create thread to monitor everything
// create thread for each phil and pass the routine
// join all threads
// join monitor thread



// routine

// time which group starts when with eating (avoid deadlock)

// while loop that checks for dead philosophers
// philo_eating fct
// schlafen -> print msg & wartet bis aufwachen
// thinkjing -> print msg & wait for finish
// loop goes forever unless someone dies


// ft_eat
// figure out order in which they take the forks
// case if only one phil
//
