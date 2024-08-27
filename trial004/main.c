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
