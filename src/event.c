#include "../inc/fract-ol.h"

int    key_hook(int keycode, t_data *data)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == KEY_LEFT || keycode == KEY_RIGHT ||
             keycode == KEY_UP || keycode == KEY_DOWN)
    {
        move(data, keycode);
        redraw(data);
    }
    return (0);
}

int    mouse_hook(int button, int x, int y, t_data *data)
{
    if (button == SCROLL_UP || button == SCROLL_DOWN)
    {
        zoom(data, x, y, button == SCROLL_UP);
        redraw(data);
    }
    return (0);
}

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
    move_factor = 0.05;
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

	// 再描画してるだけ
    y = 0;
    while (y < WINDOW_SIZE)
    {
        x = 0;
        while (x < WINDOW_SIZE)
        {
            calculate_mandelbrot(data, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
