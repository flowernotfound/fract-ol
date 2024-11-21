/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:31:27 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 17:31:28 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

static void	move_left(t_data *data, double range_r, double move_factor)
{
	data->min_r -= range_r * move_factor;
	data->max_r -= range_r * move_factor;
}

static void	move_right(t_data *data, double range_r, double move_factor)
{
	data->min_r += range_r * move_factor;
	data->max_r += range_r * move_factor;
}

static void	move_up(t_data *data, double range_i, double move_factor)
{
	data->min_i -= range_i * move_factor;
	data->max_i -= range_i * move_factor;
}

static void	move_down(t_data *data, double range_i, double move_factor)
{
	data->min_i += range_i * move_factor;
	data->max_i += range_i * move_factor;
}

void	move(t_data *data, int direction)
{
	double	move_factor;
	double	range_r;
	double	range_i;

	range_r = data->max_r - data->min_r;
	range_i = data->max_i - data->min_i;
	move_factor = 0.07;
	if (direction == KEY_LEFT)
		move_left(data, range_r, move_factor);
	else if (direction == KEY_RIGHT)
		move_right(data, range_r, move_factor);
	else if (direction == KEY_UP)
		move_up(data, range_i, move_factor);
	else if (direction == KEY_DOWN)
		move_down(data, range_i, move_factor);
}
