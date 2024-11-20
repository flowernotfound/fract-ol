#include "../inc/fract-ol.h"

int    key_hook(int keycode, t_data *data)
{
    if (keycode == KEY_ESC)
    {
        clean_exit(data);
    }
    else if (keycode == KEY_LEFT || keycode == KEY_RIGHT ||
             keycode == KEY_UP || keycode == KEY_DOWN)
    {
        move(data, keycode);
        redraw(data);
    }
    else if (keycode == KEY_C)
    {
        data->color_shift += 0x100000;
        redraw(data);
    }
    return (0);
}
