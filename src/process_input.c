/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:41 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 18:51:38 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

char	*process_input(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!str[i] || !is_digit(str[i]))
			return (NULL);
	}
	else if (!is_digit(str[i]))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (!str[i] || !is_digit(str[i]))
				return (NULL);
		}
		else if (!is_digit(str[i]))
			return (NULL);
		i++;
	}
	return ((char *)str);
}
