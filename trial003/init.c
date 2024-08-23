/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:27:05 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/23 17:26:02 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// wir kreieren so viele threads wie philos
// jeder philo fuehrt aufgaben nach einer bestimmten reihenfolge durch
// damit wir keine probleme mit geteilten resoourcen bekommen, brauchen wir mutex
// um ein deadlock zu vermeinden startet jeder ungerade philo kurz spaeter mit den aufgaben
//

// void	*ft_routine(void *i)
// {
// 	printf("hello world\n");
// 	return NULL;
// }

//where do i get the threads???
// int	ft_create_threads(t_table *table)
// {
// 	int	i;
// 	int	num_of_phil;
// 	int *ids;

// 	i = 0;
// 	num_of_phil = table->philos[0]->input.number_of_philos;
// 	ids = malloc(sizeof(int) * num_of_phil);
// 	while (i < num_of_phil)
// 	{
// 	//	ids[i] = i;
// 		// how to pass arg instead of NULL
// 		if(pthread_create(&table->threads_phil[i], NULL, &ft_routine, &ids[i]) != 0)
// 			return 1; // handle error
// 		// printf("thread %d has started\n", i);
// 		i++;
// 	}
// 	return (0);
// }

t_input *ft_init_input(char **arg)
{
	// init input
	t_input	*input;
	input = malloc(sizeof(t_input));
	if (!input)
		return NULL;
	input->number_of_philos = ft_atoi(arg[1]);
	input->time_to_die = ft_atoi(arg[2]);
	input->time_to_eat = ft_atoi(arg[3]);
	input->time_to_sleep = ft_atoi(arg[4]);
	if (arg[5])
		input->num_of_meals = ft_atoi(arg[5]);
	else
		input->num_of_meals = -1; // flag that we have no input for num of meals
	return (input);
}

void	ft_init_forks(t_table *table)
{
	int	num_phil = table->philos->input.number_of_philos;
	int i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * num_phil);
	if (!table->forks)
		table->forks = NULL;
	while (i < num_phil)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			table->forks = NULL;
		i++;
	}
}


t_table *ft_init(t_input input)
{

	t_table *table;
	table = malloc(sizeof(t_table));
	if (!table)
	{
		//free input here
		return NULL;
	}
	table->philos = malloc(sizeof(t_philo) * input.number_of_philos);
	if (!table->philos)
	{
		NULL;
	}
	ft_init_forks(table);
	if (table->forks == NULL)
		return NULL;
	ft_init_philo(input, table);
	if (table->philos == NULL)
		return NULL;
	table->start_time = 0;
	table->is_dead = false;
	if (pthread_mutex_init(&(table->m_print), NULL) != 0)
		NULL;
	if (pthread_mutex_init(&(table->m_meal), NULL) != 0)
		NULL;
	if (pthread_mutex_init(&(table->m_death), NULL) != 0)
		NULL;
	return (table);
}

void ft_init_philo(t_input input, t_table *table)
{
	int		i;

	i = 0;
	while(i < input.number_of_philos)
	{
		table->philos[i].philo_id = i;
		table->philos[i].input = input;
		table->philos[i].meals_eaten = 0;
		table->philos[i].eating = false;
		table->philos[i].finished_eating = false;
		table->philos[i].t_last_meal = ft_timestamp();
		table->philos[i].m_left_fork = &table->forks[i];
		table->philos[i].m_right_fork = &table->forks[(i + 1) % input.number_of_philos];
		table->philos[i].table = table;

		i++;
	}
}
