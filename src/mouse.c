/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:53 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 14:48:54 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

int    mouse_hook(int button, int x, int y, t_data *data)
{
    if (button == SCROLL_UP || button == SCROLL_DOWN)
    {
        zoom(data, x, y, button == SCROLL_UP);
        redraw(data);
    }
    return (0);
}
