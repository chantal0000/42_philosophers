/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:24:43 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/09 13:20:09 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// validation check that + and - are allowd?
// check for INT_MAX by checking for length but what about 999 999 999 99

// as many threads as philosophers
// one thread extra that observes?

int	main(int argc, char **argv)
{
	t_data	data;
	t_phil	phil;
	// validate input
	if (ft_validate_input(argc -1, argv + 1) != 0)
		ft_error_exit("invalid input");

	// init the data
	// dinner start
	// clean up -> if philo full | 1 philo died
	return (0);
}
