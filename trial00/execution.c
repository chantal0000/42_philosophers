/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:44:59 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/09 12:19:10 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// whaat if just one philosopher?

void	*ft_eating(t_philo *philos)
{
	t_data *data;

	data = philos->data;
	// lock data->dead
	pthread_mutex_lock(&(data->dead));
	//as long as no one died
	if (!philos->data->died)
	{
		pthread_mutex_unlock(&(data->dead));
		pthread_mutex_lock(&(data->fork[philos->left_fork]));
		// function to print out action
		pthread_mutex_lock(&(data->fork[philos->right_fork]));
		//acton
		//action
		
	}
}



// main loop for each philos behaviour (eating, sleeping and thinking)
void	*ft_routine(void *philo)
{
	// WHY COID PHILO
	t_data	*data;
	int		i;
	t_philo	*philos;

	i = 0;
	//???
	philos = (t_philo *)philo;
	//deadlock??? small delay for some philos to prevent deadlock
	//ft_deadlock ADD LATER
	data = philos->data;
	if (data->number_of_philosophers == 1)
		// return 1 philo???
	// if there are more than 1 philo we go in the loop as long as no philo died
	while(!data->died)
	{
		// actions here

		// eating: pick up fork and eat update status
		ft_eating(philos);
		// check eating count, check if philo has eaten for the req numb

		// sleeping

		// thinking

		// check for death
	}
}

// points to my data which also includes the struct of the philos
void	ft_start_simulation(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = data->philos;
	// init the start time
	data->first_timestamp = ft_timestamp();
	// loop runs from 1 to number of philo creating a thread for each
	// eachh thread runt the ft_philo_action function and passes it the data
	i = 1;
	while (i <= data->number_of_philosophers)
	{
		if (pthread_create(&(philos[i].thread_id), NULL, ft_routine, &(philos[i])));
			// error function here
	}

}
