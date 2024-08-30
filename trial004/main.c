/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:23:11 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/30 17:46:46 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// function to test print my data table

void print_table_info(t_table *table)
{
    printf("Number of Philosophers: %d\n", table->nb_of_philos);
    printf("Time to Die: %d ms\n", table->time_to_die);
    printf("Time to Eat: %d ms\n", table->time_to_eat);
    printf("Time to Sleep: %d ms\n", table->time_to_sleep);
    printf("Number of Meals (if set): %d\n", table->nb_of_meals);
    printf("Dead Flag: %s\n", table->dead_flag ? "true" : "false");
    printf("Start Time: %lld ms\n", table->start_time);

    printf("Forks initialized: %s\n", table->forks ? "Yes" : "No");

    printf("\nPhilosophers Info:\n");
    for (int i = 0; i < table->nb_of_philos; i++)
    {
        t_philo *philo = &table->philos[i];
        printf("Philosopher %d:\n", philo->id);
        printf("  Number of Meals Eaten: %d\n", philo->nb_of_meals_eaten);
        // printf("  Is Eating: %s\n", philo->eating ? "Yes" : "No");
        // printf("  Done Eating: %s\n", philo->done_eating ? "Yes" : "No");
        printf("  Time Since Last Meal: %lld ms\n", philo->timestamp_last_meal);
        printf("  Left Fork Address: %p\n", (void *)philo->m_left_fork);
        printf("  Right Fork Address: %p\n", (void *)philo->m_right_fork);
    }

    printf("\nOther Mutexes:\n");
    printf("  Print Mutex: %p\n", (void *)&table->m_print);
    // printf("  Death Mutex: %p\n", (void *)&table->m_dead);
    // printf("  Meal Mutex: %p\n", (void *)&table->m_meal);
}


int	main(int argc, char **argv)
{
	t_table	*table;
	// check input validity
	// if (ft_validate_input(argc - 1 , argv + 1) != 0)
	// {
	// 	printf("invalid input\n");
	// 	return (1);
	// }
	//	ft_error_exit("invalid input\n");
	// fill the data structures & init
	table = malloc(sizeof(t_table));
	if (ft_init(table, argv) != 0)
		return (1); // handle error
	//print_table_info(table);
	//if (table == NULL)
	//	ft_error_free(table, input, "error table init\n");
	//start procedure
	if (ft_start_procedure(table) != 0)
		return (1); // handle error
	// free(input);
	// print_table(table);
	// start routine
	//clean up
	// ft_error_free(table, input, "error\n");
	ft_clean_up(table);
	return (0);
}
