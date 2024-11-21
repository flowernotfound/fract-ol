/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:43:27 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/25 02:59:26 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_digits(unsigned long long p)
{
	int	digits;

	digits = 0;
	if (p == 0)
		return (1);
	while (p)
	{
		digits++;
		p /= 16;
	}
	return (digits);
}

static char	*p_to_hex(unsigned long long p)
{
	char	*hex;
	char	*result;
	int		digits;

	hex = "0123456789abcdef";
	digits = hex_digits(p);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result == NULL)
		return (NULL);
	result[digits] = '\0';
	while (digits)
	{
		digits--;
		result[digits] = hex[p % 16];
		p /= 16;
	}
	return (result);
}

int	print_ptr(unsigned long long p)
{
	int		length;
	int		total_length;
	char	*str_p;

	str_p = p_to_hex(p);
	if (str_p == NULL)
		return (0);
	length = ft_strlen(str_p);
	total_length = length + 2;
	write(1, "0x", 2);
	write(1, str_p, length);
	free(str_p);
	return (total_length);
}
