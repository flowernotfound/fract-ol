/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:15:43 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/25 03:01:14 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_digits(unsigned int number)
{
	int	digits;

	digits = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		digits++;
		number /= 16;
	}
	return (digits);
}

static char	*hex_to_str(unsigned int number, int flag)
{
	char	*hex_low;
	char	*hex_up;
	char	*result;
	int		digits;

	hex_low = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	digits = hex_digits(number);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result == NULL)
		return (NULL);
	result[digits] = '\0';
	while (digits)
	{
		digits--;
		if (flag)
			result[digits] = hex_up[number % 16];
		else
			result[digits] = hex_low[number % 16];
		number /= 16;
	}
	return (result);
}

int	print_hex(unsigned int number, int flag)
{
	int		length;
	char	*s;

	length = 0;
	s = hex_to_str(number, flag);
	if (s == NULL)
		return (0);
	length = ft_strlen(s);
	write(1, s, length);
	free(s);
	return (length);
}
