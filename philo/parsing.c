/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:49:57 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/17 21:03:17 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

long	ft_atol(const char *str)
{
	long	num;
	int		i;
	int		is_negative;

	is_negative = 1;
	num = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * is_negative);
}

static int	check_num(char	*nbr)
{
	if (!(*nbr == '+' || *nbr == '-' || (*nbr >= '0' && *nbr <= '9')))
		return (0);
	if ((*nbr == '+' || *nbr == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (0);
	while (*++nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (0);
	}
	return (1);
}

static int	check_input(char *argv, int index)
{
	long	num;

	if (!check_num(argv))
		return (0);
	num = ft_atol(argv);
	if ((index == 1 && num <= 0) || (index == 5 && num <= 0)
		|| num < INT_MIN || num > INT_MAX || num < 0)
		return (0);
	return (1);
}

int	parse_args(char **argv)
{
	int		i;

	i = 1;
	while (i <= 4)
	{
		if (!check_input(argv[i], i))
			return (0);
		i++;
	}
	if (argv[i] != NULL)
		if (!check_input(argv[i], i))
			return (0);
	return (1);
}
