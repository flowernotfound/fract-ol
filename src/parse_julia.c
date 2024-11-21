/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:45 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 21:38:04 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	check_julia_range(double value)
{
	return (value >= -2.0 && value <= 2.0);
}

static int	parse_julia_param(const char *str, double *value)
{
	double	result;
	char	*processed;

	processed = process_input(str);
	if (processed == NULL)
	{
		ft_printf("Invalid format\n");
		return (0);
	}
	result = ft_atof(processed);
	if (result == ERROR_VALUE)
	{
		ft_printf("Invalid parameter for Julia set\n");
		return (0);
	}
	if (!check_julia_range(result))
	{
		ft_printf("Parameter must be between -2.0 and 2.0\n");
		return (0);
	}
	*value = result;
	return (1);
}

int	handle_julia_args(int ac, char **av, t_data *data)
{
	double	julia_i;
	double	julia_r;

	if (ac != 4)
	{
		print_usage();
		return (1);
	}
	if (!parse_julia_param(av[2], &julia_r))
	{
		ft_printf("Invalid first parameter for Julia set\n");
		return (1);
	}
	if (!parse_julia_param(av[3], &julia_i))
	{
		ft_printf("Invalid second parameter for Julia set\n");
		return (1);
	}
	init_julia(data, julia_r, julia_i);
	return (0);
}
