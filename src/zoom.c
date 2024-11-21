#include "../inc/fract-ol.h"

void    zoom(t_data *data, int x, int y, int zoom_in)
{
    double  mouse_r;
    double  mouse_i;
    double  zoom_factor;

    mouse_r = data->min_r + (double)x * (data->max_r - data->min_r) / WINDOW_SIZE;
    mouse_i = data->min_i + (double)y * (data->max_i - data->min_i) / WINDOW_SIZE;
    if (zoom_in)
        zoom_factor = 0.9;
    else
        zoom_factor = 1.1;
    data->min_r = mouse_r + (data->min_r - mouse_r) * zoom_factor;
    data->max_r = mouse_r + (data->max_r - mouse_r) * zoom_factor;
    data->min_i = mouse_i + (data->min_i - mouse_i) * zoom_factor;
    data->max_i = mouse_i + (data->max_i - mouse_i) * zoom_factor;
}
