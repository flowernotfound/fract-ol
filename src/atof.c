/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:49:23 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/22 17:54:01 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	check_overflow_mul(double current, double factor)
{
	if (current > 0 && factor > MAX_VAL / current)
		return (ERROR_VALUE);
	return (0);
}

static double	convert_decimal(const char *str, int *i)
{
	double	decimal;
	double	power;
	int		decimal_count;

	decimal = 0.0;
	power = 0.1;
	decimal_count = 0;
	(*i)++;
	while (str[*i] && is_digit(str[*i]))
	{
		decimal += (str[*i] - '0') * power;
		power *= 0.1;
		decimal_count++;
		if (decimal_count > 15)
			return (ERROR_VALUE);
		(*i)++;
	}
	return (decimal);
}

static double	convert_integer(const char *str, int *i)
{
	double	value;

	value = 0.0;
	while (str[*i] && str[*i] != '.')
	{
		if (check_overflow_mul(value, 10.0))
			return (ERROR_VALUE);
		value = value * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (value);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	value;
	double	decimal;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	value = convert_integer(str, &i);
	if (value == ERROR_VALUE)
		return (ERROR_VALUE);
	decimal = 0.0;
	if (str[i] == '.')
	{
		decimal = convert_decimal(str, &i);
		if (decimal == ERROR_VALUE)
			return (ERROR_VALUE);
	}
	return ((value + decimal) * sign);
}
