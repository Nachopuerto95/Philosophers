/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:30:37 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/18 17:40:16 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	write_status(char *status, t_philo *philo)
{
	time_t	time;

	pthread_mutex_lock(&philo->table->write_mtx);
	time = get_now_time(philo->table);
	if (is_simulation_end(philo->table) || all_philos_ate(philo->table))
	{
		pthread_mutex_unlock(&philo->table->write_mtx);
		return ;
	}
	if (ft_strncmp(status, EATING, 6) == 0)
		printf("%6ld %i is eating\n", time, philo->id);
	if (ft_strncmp(status, SLEEPING, 8) == 0)
		printf("%6ld %i is sleeping\n", time, philo->id);
	if (ft_strncmp(status, THINKING, 8) == 0)
		printf("%6ld %i is thinking\n", time, philo->id);
	if (ft_strncmp(status, DIED, 4) == 0)
		printf("%6ld %i died\n", time, philo->id);
	if (ft_strncmp(status, FORK_1, 6) == 0)
		printf("%6ld %i has taken a fork\n", time, philo->id);
	if (ft_strncmp(status, FORK_2, 6) == 0)
		printf("%6ld %i has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(&philo->table->write_mtx);
}
