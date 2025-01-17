/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:39:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/09/01 11:30:15 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_validate_input(int count, char **input)
{
	int	i;

	i = 1;
	if (count == 5 || count == 6)
	{
		while (i < count)
		{
			if (ft_atoi(input[i]) <= 0)
				return (1);
			if (ft_atoi(input[i]) > INT_MAX)
				return (1);
			i++;
		}
		if (ft_atoi(input[1]) > 200)
			return (1);
		return (0);
	}
	return (1);
}
