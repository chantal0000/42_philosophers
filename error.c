/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:03:02 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/02 11:04:25 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// writes error_message in red
// and exits the program
void	ft_error_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}
