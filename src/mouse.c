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
