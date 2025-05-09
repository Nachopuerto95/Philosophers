/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:29:00 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/18 18:24:30 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	*one_philo_routine(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	philo->table->start_sim = get_time();
	write_status(FORK_1, philo);
	philo_sleep(philo->table, philo->table->time_die);
	write_status(DIED, philo);
	return (0);
}

void	*philo_pre_rutine(void *data)
{
	t_philo				*philo;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*second_fork;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->table->table_mutex);
	philo->table->start_sim = get_time();
	pthread_mutex_unlock(&philo->table->table_mutex);
	if (philo->id % 2 == 0)
	{
		first_fork = philo->left_fork;
		second_fork = &philo->right_fork;
		usleep(350);
	}
	else
	{
		first_fork = &philo->right_fork;
		second_fork = philo->left_fork;
	}
	philo_routine(philo, first_fork, second_fork);
	return (0);
}

void	philo_routine(t_philo *philo, pthread_mutex_t *first_fork,
			pthread_mutex_t *second_fork)
{
	while (!is_simulation_end(philo->table) && !(has_eaten(philo)))
	{
		pthread_mutex_lock(first_fork);
		write_status(FORK_2, philo);
		pthread_mutex_lock(second_fork);
		write_status(FORK_1, philo);
		write_status(EATING, philo);
		pthread_mutex_lock(&philo->table->table_mutex);
		pthread_mutex_lock(&philo->philo_mutex);
		philo->last_meal = get_time() - philo->table->start_sim;
		philo->meals += 1;
		pthread_mutex_unlock(&philo->philo_mutex);
		pthread_mutex_unlock(&philo->table->table_mutex);
		philo_sleep(philo->table, philo->table->time_eat);
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		if (is_simulation_end(philo->table) || has_eaten(philo))
			return ;
		write_status(SLEEPING, philo);
		philo_sleep(philo->table, philo->table->time_sleep);
		write_status(THINKING, philo);
	}
}

void	*monitoring(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!is_simulation_end(table) && !(all_philos_ate(table)))
	{
		i = -1;
		while (++i < table->philos_nb)
		{
			if (all_philos_ate(table))
				return (0);
			else if (!is_philo_alive(table->philos[i]))
			{
				write_status(DIED, table->philos[i]);
				pthread_mutex_lock(&table->table_mutex);
				table->end_sim = true;
				pthread_mutex_unlock(&table->table_mutex);
				return (0);
			}
		}
	}
	return (0);
}
