#include "../inc/fract-ol.h"

// main.c に追加
void	clean_exit(t_data *data)
{
    if (data->img.img)
        mlx_destroy_image(data->mlx, data->img.img);
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    #ifdef __linux__
        if (data->mlx)
            mlx_destroy_display(data->mlx);
    #endif
    if (data->mlx)
        free(data->mlx);
    exit(0);
}

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
