/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:23:11 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/23 15:54:31 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	print_table(t_table *table)
{
	int i = 0;

	printf("---------------------------------------------------------------\n");
	printf("t_table:\n");
	printf("table->start_time %lld\n", table->start_time);
	while (i < table->philos->input.number_of_philos)
	{
		printf("\n");
		printf("phil: i %d\n", i);
		printf("philo_id %d\n", table->philos[i].philo_id);
		printf("input.number_of_philos %d\n", table->philos[i].input.number_of_philos);
		printf("input->time_to_die %d\n", table->philos[i].input.time_to_die);
		printf("input->time_to_eat %d\n", table->philos[i].input.time_to_eat);
		printf("input->time_to_sleep %d\n", table->philos[i].input.time_to_die);
		printf("input->num_of_meals %d\n", table->philos[i].input.num_of_meals);
		i++;
	}
	printf("\n");
	printf("---------------------------------------------------------------\n");
}


int	main(int argc, char **argv)
{
	t_table	*table;
	t_input	*input;
	// check input validity
	if (ft_validate_input(argc - 1 , argv + 1) != 0)
		ft_error_exit("invalid input\n");
	// fill the data structures & init
	input = ft_init_input(argv);
	if (input == NULL)
		ft_error_exit("error input init\n");
	table = ft_init(*input);
	if (table == NULL)
		ft_error_free(table, input, "error table init\n");
	//start procedure
	ft_start_procedure(table);
	// free(input);
	// print_table(table);
	// start routine
	//clean up
	ft_error_free(table, input, "error\n");
	return (0);
}
