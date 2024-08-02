/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:54:19 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/02 15:16:48 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long long	ft_timestamp()
{
	// just for now
	return (100);
}

void	ft_init_mutex(t_data *data)
{
	int	i;

	data->fork = malloc(sizeof(pthread_mutex_t) * (data->number_of_philosophers + 1));
	if (!data->fork)
		ft_error_exit("init mutex failed\n");

	i = data->number_of_philosophers + 1;
	while (i >= 1)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			ft_error_exit("init mutex failed\n");
		i--;
	}
	if (pthread_mutex_init(&(data->meal), NULL))
		ft_error_exit("init mutex failed\n");
	if (pthread_mutex_init(&(data->dead), NULL))
		ft_error_exit("init mutex failed\n");

}



// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

t_philo *ft_init_philos(t_data *data)
{
	t_philo *philos;
	int	i;

	i = 0;
	philos = malloc(sizeof(t_philo) * (data->number_of_philosophers));
	if (!philos)
		ft_error_exit("init philos failed\n");
	while (i <= data->number_of_philosophers)
	{
		data->philos[i].data = data;
		data->philos[i].id = i;
		data->philos[i].id_ate = 0;
		data->philos[i].last_meal = ft_timestamp();
		data->philos[i].left_fork = i - 1;
		data->philos[1].left_fork = data->number_of_philosophers;
		data->philos[i].right_fork = i;
		i++;
	}
}


// initializing the user input
int	ft_init(t_data *data, char **input)
{
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		ft_error_exit("init failed\n");
	data->number_of_philosophers = ft_atoi(input[0]);
	data->time_to_die = ft_atoi(input[1]);
	data->time_to_eat = ft_atoi(input[2]);
	data->time_to_sleep = ft_atoi(input[3]);
	if (input[4])
		data->times_must_eat = ft_atoi(input[4]);
	else
		data->times_must_eat = -1;
	data->died = 0;
	data->philos = ft_init_philos(data);
	// init mutex?
	ft_init_mutex(data);
}
