/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:49:20 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 18:31:46 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

int	get_color(int iteration, int max_iteration, int shift)
{
	if (iteration == max_iteration)
		return (0x000000);
	return ((iteration * 0xFF0000 / max_iteration + shift) & 0xFFFFFF);
}

int	get_pixel_color(int iter, t_data *data)
{
	if (iter == data->max_iter)
		return (0x000000);
	return (get_color(iter, data->max_iter, data->color_shift));
}
