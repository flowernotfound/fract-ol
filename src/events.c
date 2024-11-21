/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:49:17 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 18:51:06 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	redraw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_SIZE)
	{
		x = 0;
		while (x < WINDOW_SIZE)
		{
			if (data->type == MANDELBROT)
				calculate_mandelbrot(data, x, y);
			else if (data->type == JULIA)
				calculate_julia(data, x, y);
			else if (data->type == TRICORN)
				calculate_tricorn(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	handle_expose(t_data *data)
{
	redraw(data);
	return (0);
}

int	close_window(t_data *data)
{
	clean_exit(data);
	return (0);
}
