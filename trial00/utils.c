/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:25:25 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/02 11:03:54 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



// check if char *str only contains of numbers
int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}
// turn char *str into int
int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (sign == -1)
	{
		return (result * sign);
	}
	return (result);
}
// function to validate the given arguments
// returns 0 if valid, return 1 if invalid

// arguments to check:
	// [0] number_of_philosophers
	// [1] time_to_die
	// [2] time_to_eat
	// [3] time_to_sleep
	// OPTIONAL [4] [number_of_times_each_philosopher_must_eat]

// conditions to check:
// min 4 arguments && max 5 arguments ✅
// max 200 philosophers
// all input should be only numbers ✅
// should things be bigger than 1? not less than 60ms
int	ft_validate_input(int count, char **input)
{
	int i;

	i = 0;
	if (count > 5 || count < 4)
		return (1);
	if (ft_atoi(input[0]) > 200)
		return (1);
	while (i < count)
	{
		if (ft_isdigit(input[i]) != 0)
			return (1);
		i++;
	}
	printf("input is valid\n");
	return (0);
}


