#include "../inc/fract-ol.h"

void    calculate_tricorn(t_data *data, int x, int y)
{
    double  c_r;
    double  c_i;
    double  z_r;
    double  z_i;
    int     iter;
    double  tmp;

    c_r = data->min_r + (double)x * (data->max_r - data->min_r) / WINDOW_SIZE;
    c_i = data->min_i + (double)y * (data->max_i - data->min_i) / WINDOW_SIZE;
    z_r = 0;
    z_i = 0;
    iter = 0;
    while (z_r * z_r + z_i * z_i <= 4 && iter < data->max_iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = -2 * tmp * z_i + c_i;  // 共役にしてるだけ
        iter++;
    }
    int color;
    if (iter == data->max_iter)
        color = 0x000000;
    else
        color = get_color(iter, data->max_iter, data->color_shift);
    my_mlx_pixel_put(&data->img, x, y, color);
}
