/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:49 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 21:33:41 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	print_usage(void)
{
	ft_printf("Usage: ./fractol <type> [julia_r julia_i]\n");
	ft_printf("type: mandelbrot or julia or tricorn\n");
	ft_printf("\nExamples:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia 0.285 0.01\n");
	ft_printf("  ./fractol tricorn\n");
	ft_printf("\nJulia set parameters:\n");
	ft_printf("  - Must be numbers between -2.0 and 2.0\n");
	ft_printf("  - Examples of valid parameters:\n");
	ft_printf("    0.285 0.01\n");
	ft_printf("    -0.4 0.6\n");
	ft_printf("    0.0 -0.8\n");
}

static int	handle_fractal_type(int ac, char **av, t_data *data)
{
	if (strcmp(av[1], "mandelbrot") == 0)
	{
		init_mandelbrot(data);
		return (0);
	}
	if (ft_strcmp(av[1], "julia") == 0)
		return (handle_julia_args(ac, av, data));
	if (ft_strcmp(av[1], "tricorn") == 0)
	{
		init_tricorn(data);
		return (0);
	}
	ft_printf("Invalid fractal type\n");
	print_usage();
	return (1);
}

int	parse_args(int ac, char **av, t_data *data)
{
	if (ac < 2 || ac > 4)
	{
		print_usage();
		return (1);
	}
	return (handle_fractal_type(ac, av, data));
}
