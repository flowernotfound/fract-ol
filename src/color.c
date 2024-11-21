/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:49:20 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 14:49:21 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

int	get_color(int iteration, int max_iteration, int shift)
{
	if (iteration == max_iteration)
		return (0x000000);
	return ((iteration * 0xFF0000 / max_iteration + shift) & 0xFFFFFF);
}
