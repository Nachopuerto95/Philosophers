/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:51:55 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/18 15:01:35 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	init_simulation(t_table *table)
{
	int	i;

	i = -1;
	if (table->threads_rdy == true)
	{
		while (++i < table->philos_nb)
			pthread_join(table->philos[i]->thread_id, NULL);
		if (table->philos_nb > 1)
			pthread_join(table->god, NULL);
	}
}

void	init_threads(t_table *table)
{
	int	i;

	i = 0;
	if (table->philos_nb == 1)
	{
		pthread_create(&table->philos[i]->thread_id, NULL,
			one_philo_routine, (void *)table->philos[i]);
	}
	else
	{
		while (i < table->philos_nb)
		{
			pthread_create(&table->philos[i]->thread_id, NULL,
				philo_pre_rutine, (void *)table->philos[i]);
			i++;
		}
		pthread_create(&table->god, NULL, monitoring, (void *)table);
	}
	pthread_mutex_lock(&table->table_mutex);
	table->threads_rdy = true;
	pthread_mutex_unlock(&table->table_mutex);
}

t_philo	**init_philos(t_table *table)
{
	t_philo		**all_philos;
	int			i;

	i = 0;
	all_philos = ft_calloc(sizeof(t_philo *), table->philos_nb);
	if (!all_philos)
		return (NULL);
	while (i < table->philos_nb)
	{
		all_philos[i] = ft_calloc(sizeof(t_philo), 1);
		if (i == 0)
			all_philos[i]->left_fork = NULL;
		else
			all_philos[i]->left_fork = &all_philos[i - 1]->right_fork;
		all_philos[i]->id = i + 1;
		all_philos[i]->meals = 0;
		all_philos[i]->must_eat = table->must_eat;
		all_philos[i]->table = table;
		all_philos[i]->last_meal = 0;
		pthread_mutex_init(&all_philos[i]->right_fork, NULL);
		i++;
	}
	if (table->philos_nb > 1)
		all_philos[0]->left_fork = &all_philos[i - 1]->right_fork;
	return (all_philos);
}

void	init_mutexes(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_init(&table->table_mutex, NULL);
	pthread_mutex_init(&table->write_mtx, NULL);
	while (i < table->philos_nb)
	{
		pthread_mutex_init(&table->philos[i]->philo_mutex, NULL);
		i++;
	}
}

t_table	*init_table(int argc, char **argv)
{
	t_table		*table;

	table = ft_calloc(sizeof(t_table), 1);
	table->philos_nb = ft_atol(argv[0]);
	table->time_die = ft_atol(argv[1]);
	table->time_eat = ft_atol(argv[2]);
	table->time_sleep = ft_atol(argv[3]);
	table->threads_rdy = false;
	if (argc == 5)
		table->must_eat = ft_atol(argv[4]);
	table->philos = init_philos(table);
	init_mutexes(table);
	return (table);
}
