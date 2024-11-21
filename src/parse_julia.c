/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:45 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 14:48:46 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

int check_julia_range(double value)
{
    return (value >= -2.0 && value <= 2.0);
}

int parse_julia_param(const char *str, double *value)
{
	double result;
    char *processed;

    processed = process_input(str);
    if (processed == NULL)
    {
        printf("Invalid format\n");
        return (0);
    }
	result = ft_atof(processed);
	printf("result: %f\n", result);
	if (result == ERROR_VALUE)
	{
		printf("Invalid parameter for Julia set\n");
		return (0);
	}
    if (!check_julia_range(result))
    {
        printf("Parameter must be between -2.0 and 2.0\n");
        return (0);
    }
	*value = result;
    return (1);
}

int handle_julia_args(int ac, char **av, t_data *data)
{
    double julia_i;
    double julia_r;

    if (ac != 4)
    {
        print_usage();
        return (1);
    }
    if (!parse_julia_param(av[2], &julia_r))
    {
        printf("Invalid first parameter for Julia set\n");
        return (1);
    }
    if (!parse_julia_param(av[3], &julia_i))
    {
        printf("Invalid second parameter for Julia set\n");
        return (1);
    }
    init_julia(data, julia_r, julia_i);
    return (0);
}
