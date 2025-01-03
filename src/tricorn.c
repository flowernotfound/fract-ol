/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:37 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 18:51:42 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	calculate_iterations(double c_r, double c_i, int max_iter)
{
	double	z_r;
	double	z_i;
	double	tmp;
	int		iter;

	z_r = 0;
	z_i = 0;
	iter = 0;
	while (z_r * z_r + z_i * z_i <= 4 && iter < max_iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = -2 * tmp * z_i + c_i;
		iter++;
	}
	return (iter);
}

void	calculate_tricorn(t_data *data, int x, int y)
{
	double	c_r;
	double	c_i;
	int		iter;
	int		color;

	c_r = data->min_r + (double)x * (data->max_r - data->min_r) / WINDOW_SIZE;
	c_i = data->min_i + (double)y * (data->max_i - data->min_i) / WINDOW_SIZE;
	iter = calculate_iterations(c_r, c_i, data->max_iter);
	color = get_pixel_color(iter, data);
	my_mlx_pixel_put(&data->img, x, y, color);
}
