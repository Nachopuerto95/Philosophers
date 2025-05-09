/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:29:47 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/18 18:24:35 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	philo_sleep(t_table *table, int time)
{
	time_t	wake_up;

	wake_up = get_time() + time;
	while (get_time() < wake_up)
	{
		if (is_simulation_end(table))
			break ;
	}
}

time_t	get_now_time(t_table *table)
{
	time_t	time;

	pthread_mutex_lock(&table->table_mutex);
	time = get_time() - table->start_sim;
	pthread_mutex_unlock(&table->table_mutex);
	return (time);
}

time_t	get_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
