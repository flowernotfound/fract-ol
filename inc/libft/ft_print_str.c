/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 01:47:49 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/23 01:57:21 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s)
{
	int	count;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen(s);
	write(1, s, count);
	return (count);
}
