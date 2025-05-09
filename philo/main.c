/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:06:30 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/17 20:01:41 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	*free_table(t_table *table)
{
	int	i;

	if (!table)
		return (NULL);
	if (table->philos)
	{
		i = 0;
		while (i < table->philos_nb)
		{
			if (table->philos[i])
				free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
	free(table);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_table		*table;

	table = NULL;
	if ((argc < 5) || argc > 6 || !parse_args(argv))
		return (write(2, "Invalid args\n", 13), 1);
	table = init_table(argc - 1, argv + 1);
	init_threads(table);
	init_simulation(table);
	destroy_mutexes(table);
	free_table(table);
	return (0);
}
