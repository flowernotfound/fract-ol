/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:45:09 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/24 03:11:44 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_digits(unsigned int number)
{
	int	digits;

	if (number == 0)
		return (1);
	digits = 0;
	while (number != 0)
	{
		digits++;
		number /= 10;
	}
	return (digits);
}

char	*ft_utoa(unsigned int number)
{
	char	*result;
	int		digits;

	digits = unsigned_digits(number);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result == NULL)
		return (NULL);
	result[digits] = '\0';
	if (number == 0)
		result[0] = '0';
	else
	{
		while (digits > 0)
		{
			digits--;
			result[digits] = (number % 10) + '0';
			number /= 10;
		}
	}
	return (result);
}
