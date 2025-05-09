/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:18:37 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/17 21:36:23 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	destroy_mutexes(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->table_mutex);
	pthread_mutex_destroy(&table->write_mtx);
	while (i < table->philos_nb)
	{
		pthread_mutex_destroy(&table->philos[i]->philo_mutex);
		pthread_mutex_destroy(&table->philos[i]->right_fork);
		i++;
	}
}
