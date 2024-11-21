/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:49:08 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 14:49:14 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

void    calculate_julia(t_data *data, int x, int y)
{
    double  z_r;
    double  z_i;
    int     iter;
    double  tmp;
    int color;

    z_r = data->min_r + (double)x * (data->max_r - data->min_r) / WINDOW_SIZE;
    z_i = data->min_i + (double)y * (data->max_i - data->min_i) / WINDOW_SIZE;
    iter = 0;
    while (z_r * z_r + z_i * z_i <= 4 && iter < data->max_iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + data->julia_r;
        z_i = 2 * tmp * z_i + data->julia_i;
        iter++;
    }
    if (iter == data->max_iter)
        color = 0x000000;
    else
        color = get_color(iter, data->max_iter, data->color_shift);
    my_mlx_pixel_put(&data->img, x, y, color);
}
