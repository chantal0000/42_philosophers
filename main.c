/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:24:43 by chbuerge          #+#    #+#             */
/*   Updated: 2024/06/24 15:47:00 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// as many threads as philosophers
// one thread extra that observes?


int	main(int argc, char **argv)
{
	if (ft_validate_input(argc -1, argv + 1) != 0)
		ft_error_exit("invalid input");
	return (0);
}
