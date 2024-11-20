#include "../inc/fract-ol.h"

void    init_mandelbrot(t_data *data)
{
	data->type = MANDELBROT;
    data->min_r = -2.0;
    data->max_r = 1.0;
    data->min_i = -1.5;
    data->max_i = 1.5;
    data->max_iter = 200;
	data->color_shift = 0;
}

void    init_julia(t_data *data, double julia_r, double julia_i)
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

void    init_tricorn(t_data *data)
{
    data->type = TRICORN;
    data->min_r = -2.0;
    data->max_r = 2.0;
    data->min_i = -2.0;
    data->max_i = 2.0;
    data->max_iter = 200;
    data->color_shift = 0;
}
