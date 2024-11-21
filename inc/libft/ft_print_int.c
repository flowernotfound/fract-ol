/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:25:44 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/23 03:36:07 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int number)
{
	int		length;
	char	*s;

	s = ft_itoa(number);
	if (s == NULL)
		return (0);
	length = ft_strlen(s);
	write(1, s, length);
	free(s);
	return (length);
}
