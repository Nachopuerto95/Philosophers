/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:47:10 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/26 14:54:44 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

/// @brief Allocate memory as Malloc but filled with 0
/// @return Pointer to a memory slot
void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*tab;
	size_t		i;

	i = 0;
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		tab[i] = '\0';
		i++;
	}
	return ((void *)tab);
}
