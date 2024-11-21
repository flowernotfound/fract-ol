#include "../inc/fract-ol.h"

void    zoom(t_data *data, int x, int y, int zoom_in)
{
    double  mouse_r;
    double  mouse_i;
    double  zoom_factor;

    mouse_r = data->min_r + (double)x * (data->max_r - data->min_r) / WINDOW_SIZE;
    mouse_i = data->min_i + (double)y * (data->max_i - data->min_i) / WINDOW_SIZE;
    // いったんこの倍率
    zoom_factor = zoom_in ? 0.9 : 1.1;
	// マウス位置を中心でズーム
    data->min_r = mouse_r + (data->min_r - mouse_r) * zoom_factor;
    data->max_r = mouse_r + (data->max_r - mouse_r) * zoom_factor;
    data->min_i = mouse_i + (data->min_i - mouse_i) * zoom_factor;
    data->max_i = mouse_i + (data->max_i - mouse_i) * zoom_factor;
}

void    move(t_data *data, int direction)
{
    double  move_factor;
    double  range_r;
    double  range_i;

    range_r = data->max_r - data->min_r;
    range_i = data->max_i - data->min_i;
    // 移動する量　いったんこれでやってる
    move_factor = 0.07;
    if (direction == KEY_LEFT)
    {
        data->min_r -= range_r * move_factor;
        data->max_r -= range_r * move_factor;
    }
    else if (direction == KEY_RIGHT)
    {
        data->min_r += range_r * move_factor;
        data->max_r += range_r * move_factor;
    }
    else if (direction == KEY_UP)
    {
        data->min_i -= range_i * move_factor;
        data->max_i -= range_i * move_factor;
    }
    else if (direction == KEY_DOWN)
    {
        data->min_i += range_i * move_factor;
        data->max_i += range_i * move_factor;
    }
}

void    redraw(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < WINDOW_SIZE)
    {
        x = 0;
        while (x < WINDOW_SIZE)
        {
            if (data->type == MANDELBROT)
                calculate_mandelbrot(data, x, y);
            else if (data->type == JULIA)
                calculate_julia(data, x, y);
            else if (data->type == TRICORN)
                calculate_tricorn(data, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int handle_expose(t_data *data)
{
    redraw(data);
    return (0);
}

int close_window(t_data *data)
{
	clean_exit(data);
	return (0);
}
