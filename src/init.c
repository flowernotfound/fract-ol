/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:49:11 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 14:52:13 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

void	init_mandelbrot(t_data *data)
{
	data->type = MANDELBROT;
	data->min_r = -2.0;
	data->max_r = 1.0;
	data->min_i = -1.5;
	data->max_i = 1.5;
	data->max_iter = 200;
	data->color_shift = 0;
}

void	init_julia(t_data *data, double julia_r, double julia_i)
{
	data->type = JULIA;
	data->julia_r = julia_r;
	data->julia_i = julia_i;
	data->min_r = -2.0;
	data->max_r = 2.0;
	data->min_i = -2.0;
	data->max_i = 2.0;
	data->max_iter = 200;
	data->color_shift = 0;
}

void	init_tricorn(t_data *data)
{
	data->type = TRICORN;
	data->min_r = -2.0;
	data->max_r = 2.0;
	data->min_i = -2.0;
	data->max_i = 2.0;
	data->max_iter = 200;
	data->color_shift = 0;
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WINDOW_SIZE, WINDOW_SIZE, "fract-ol");
	if (data->win == NULL)
	{
		clean_exit(data);
		return (1);
	}
	return (0);
}

int	init_window(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WINDOW_SIZE, WINDOW_SIZE);
	if (data->img.img == NULL)
	{
		clean_exit(data);
		return (1);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	return (0);
}
