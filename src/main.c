#include "../inc/fract-ol.h"

int main(int ac, char **av)
{
	t_data data;
	int x;
	int y;

    if (ac < 2)
    {
        printf("Usage: ./fractol <type> [julia_r julia_i]\n");
        printf("type: mandelbrot or julia or tricorn\n");
        return (1);
    }
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
    if (strcmp(av[1], "mandelbrot") == 0)
    {
        init_mandelbrot(&data);
    }
    else if (strcmp(av[1], "julia") == 0)
    {
        if (ac != 4)
        {
            printf("Julia set requires 2 parameters\n");
            return (1);
        }
        init_julia(&data, atof(av[2]), atof(av[3]));
    }
	else if (strcmp(av[1], "tricorn") == 0)
    	init_tricorn(&data);
    else
    {
        printf("Invalid fractal type\n");
        return (1);
    }
	data.win = mlx_new_window(data.mlx, WINDOW_SIZE, WINDOW_SIZE, "first window");
	if (data.win == NULL)
	{
		clean_exit(&data);
		return (1);
	}
    data.img.img = mlx_new_image(data.mlx, WINDOW_SIZE, WINDOW_SIZE);
	data.img.addr = mlx_get_data_addr(data.img.img,
                                 &data.img.bits_per_pixel,
                                 &data.img.line_length,
                                 &data.img.endian);
	if (data.img.img == NULL)
	{
		clean_exit(&data);
		return (1);
	}
	redraw(&data);
    mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, X_EVENT, X_MASK, close_window, &data);
	mlx_hook(data.win, EXPOSE_EVENT, EXPOSE_MASK, handle_expose, &data);
	mlx_loop(data.mlx);
	return (0);
}
