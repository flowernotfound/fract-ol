/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:49:08 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 18:16:21 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

static int	calculate_iterations(double z_r, double z_i, t_data *data)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (z_r * z_r + z_i * z_i <= 4 && iter < data->max_iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + data->julia_r;
		z_i = 2 * tmp * z_i + data->julia_i;
		iter++;
	}
	return (iter);
}

static int	get_pixel_color(int iter, t_data *data)
{
	if (iter == data->max_iter)
		return (0x000000);
	return (get_color(iter, data->max_iter, data->color_shift));
}

void	calculate_julia(t_data *data, int x, int y)
{
	double	z_r;
	double	z_i;
	int		iter;
	int		color;

	z_r = data->min_r + (double)x * (data->max_r - data->min_r) / WINDOW_SIZE;
	z_i = data->min_i + (double)y * (data->max_i - data->min_i) / WINDOW_SIZE;
	iter = calculate_iterations(z_r, z_i, data);
	color = get_pixel_color(iter, data);
	my_mlx_pixel_put(&data->img, x, y, color);
}
