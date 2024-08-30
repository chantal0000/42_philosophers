/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:39:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/30 17:46:35 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// check if char *str only contains of numbers
int	ft_isdigit(char *str)
{
	printf("string %s\n", str);
	while (*str)
	{
		if (*str < '1' || *str > '9' || *str == ' ')
			return (1);
		str++;
	}
	return (0);
}
// conditions to check:
// min 4 arguments && max 5 arguments ✅
// max 200 philosophers
// all input should be only numbers ✅
// should things be bigger than 1? not less than 60ms
int	ft_validate_input(int count, char **input)
{
	int i;

	i = 0;
	if (count == 5 || count == 4)
	{
		while (i < count)
		{
			if (ft_isdigit(input[i]) != 0)
			return (1);
		i++;
		}
	}
	if (ft_atoi(input[0]) > 200)
		return (1);

	printf("input is valid\n");
	return (0);
}
