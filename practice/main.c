/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:22:38 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/13 14:59:11 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_atoi(const char *str);

// 1. create threads in a loop & print which thread we are in

void	*ft_routine(void *arg)
{
	// int i = 0;
	int i = *(int *)arg;
	if (i % 2 != 0)
		usleep(200000);
	printf("hello from routine, thread %d\n", i);
	usleep(2000000);
	ft_routine(arg);
	// return NULL;
}

void	print_input_struct(t_input *input)
{
	printf("number_of_philos: %d\n", input->number_of_philos);
	printf("time_to_die: %d\n", input->time_to_die);
	printf("time_to_eat: %d\n", input->time_to_eat);
	printf("time_to_sleep: %d\n", input->time_to_sleep);
}

t_input *ft_init_data(char **arg)
{
	// init input
	t_input	*input;
	input = malloc(sizeof(t_input));
	if (!input)
		return NULL; //handle error
	input->number_of_philos = ft_atoi(arg[1]);
	input->time_to_die = ft_atoi(arg[2]);
	input->time_to_eat = ft_atoi(arg[3]);
	input->time_to_sleep = ft_atoi(arg[4]);
	// [number_of_times_each_philosopher_must_eat]

	return (input);
}

t_philo	*ft_init_philo(t_input input, int id)
{
	t_philo	*philo;
	philo = malloc(sizeof (t_philo *));
	philo->input = input;
	philo->philo_id = id;



	return (philo);
}


t_table ft_init_table(t_input input) {

	t_table table;

	table.philos = malloc(sizeof(t_philo) * input.number_of_philos);
	int i = 0;

	while (i < input.number_of_philos) {
		table.philos = ft_init_philo(input, i);
		i++;
	}
	// loop for initalizing philos
	// philo = ft_init_philo(input);

}

int	main(int argc, char **argv)
{
	int	i = 0;
	pthread_t thread[4];
	t_input	*input;
	t_philo *philo;
	t_table table;
	int *ids = malloc(sizeof(int) * 4);
	// 1. check if args valid
	// 2. init Data Structure
	argv[0] = "name";
	argv[1] = "4";
	argv[2] = "400";
	argv[3] = "200";
	argv[4] = "100";

	input = ft_init_data(argv);
	print_input_struct(input);
	// philo = ft_init_philo(input);
	table = ft_init_table(*input);

	while (i < 4)
	{
		ids[i] = i;
		// how to pass arg instead of NULL
		if(pthread_create(&thread[i], NULL, &ft_routine, &ids[i]) != 0)
			return 1; // handle error
		// printf("thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if(pthread_join(thread[i], NULL) != 0)
			return 1; // handle error
		// printf("thread %d has finished\n", i);
		i++;
	}
}
