/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.pseudo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:06:03 by chbuerge          #+#    #+#             */
/*   Updated: 2024/08/30 17:10:00 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// monitor if a philo dies
    // mutex for death_flag lock
    // check flag
    // unlock mutex
    // ....-> at what point do we set the flag (all the time but where)



// monitor if philos are full -> if we get the number_meals_eat

int	ft_check_for_death(t_philo *philo)
{
	long long	time;

	time = ft_timestamp() - philo->timestamp_last_meal;
	// printf("time since last eat %lld\n", time);
	if (time > philo->table->time_to_die)
		return (1);
	return (0);
}

void	*ft_monitor(void *table_input)
{
	printf("ft_monitor\n");
	t_table *table;
	int i;
	table = (t_table *)table_input;
	// loop until dead_flag true
		// printf("enters here\n");
		// printf("dead flag %s \n", table->dead_flag ? "true" : "false");
		// printf("%i\n", table->philos[0].id);
	while (table->dead_flag == false)
	{
		i = 0;
		while (i < table->nb_of_philos)
		{
			if (ft_check_for_death(&(table->philos[i])) == 1 && (table->philos[i].done_eating == false))
			{
				// printf("philo %i died\n", table->philos[i].id);
				// usleep(1000);
				table->dead_flag = true;
				pthread_mutex_lock(&table->m_print);
				printf("%lld %i died\n", ft_timestamp() - table->start_time, table->philos[i].id);
				pthread_mutex_unlock(&table->m_print);
				// ft_print(&(table->philos[i]), "died\n\n");
				// kein mutex, weil einziger thread der set
				return (0);
			}
			i++;
		}
		i = 0;
		int count = 0;
		while (i < table->nb_of_philos)
		{
			if (table->philos[i].done_eating == true)
			{
				count++;
			}
			i++;
		}
		if (count == table->nb_of_philos)
		{
			//done eating
			return (0);
		}

		usleep(1000);
	}
		// check timestamp() time_to_die
		// set dead_flag
		// usleep(1000)\

	return (0);
}
