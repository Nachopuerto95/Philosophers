/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:19:01 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/18 18:41:01 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	all_philos_ate(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_nb)
	{
		pthread_mutex_lock(&table->philos[i]->philo_mutex);
		if (table->philos[i]->must_eat > table->philos[i]->meals
			|| !table->philos[i]->must_eat)
		{
			pthread_mutex_unlock(&table->philos[i]->philo_mutex);
			return (0);
		}
		pthread_mutex_unlock(&table->philos[i]->philo_mutex);
		i++;
	}
	return (1);
}

int	has_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	if (philo->meals < philo->must_eat || !philo->must_eat)
	{
		pthread_mutex_unlock(&philo->philo_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->philo_mutex);
	return (1);
}

int	is_simulation_end(t_table *table)
{
	pthread_mutex_lock(&table->table_mutex);
	if (table->end_sim == false)
	{
		pthread_mutex_unlock(&table->table_mutex);
		return (0);
	}
	pthread_mutex_unlock(&table->table_mutex);
	return (1);
}

int	is_philo_alive(t_philo *philo)
{
	time_t	now;
	int		alive;

	if (has_eaten(philo))
		return (1);
	pthread_mutex_lock(&philo->table->table_mutex);
	now = get_time() - philo->table->start_sim;
	alive = (now - philo->last_meal <= philo->table->time_die);
	pthread_mutex_unlock(&philo->table->table_mutex);
	return (alive);
}
