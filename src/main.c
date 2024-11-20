#include "../inc/fract-ol.h"

int handle_expose(t_data *data)
{
    redraw(data);
    return (0);
}

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    calculate_mandelbrot(t_data *data, int x, int y)
{
    double  c_r;        // 実部
    double  c_i;        // 虚部
    double  z_r;        // zの実部
    double  z_i;        // zの虚部
    int     iter;
    double  tmp;

    // プロット
    c_r = data->min_r + (double)x * (data->max_r - data->min_r) / WINDOW_SIZE;
    c_i = data->min_i + (double)y * (data->max_i - data->min_i) / WINDOW_SIZE;

    z_r = 0;
    z_i = 0;
    iter = 0;
    while (z_r * z_r + z_i * z_i <= 4 && iter < data->max_iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * tmp * z_i + c_i;
        iter++;
    }

    // 発散までの回数で色決める　ちょっとここは後で考える
    int color;
    if (iter == data->max_iter)
        color = 0x000000;
    else
        color = get_color(iter, data->max_iter, data->color_shift);

    my_mlx_pixel_put(&data->img, x, y, color);
}

void    init_mandelbrot(t_data *data)
{
	data->type = MANDELBROT;
    data->min_r = -2.0;
    data->max_r = 1.0;
    data->min_i = -1.5;
    data->max_i = 1.5;
    data->max_iter = 200;
	data->color_shift = 0;  // カラーシフトの初期値
}

void    calculate_julia(t_data *data, int x, int y)
{
    double  z_r;
    double  z_i;
    int     iter;
    double  tmp;

    z_r = data->min_r + (double)x * (data->max_r - data->min_r) / WINDOW_SIZE;
    z_i = data->min_i + (double)y * (data->max_i - data->min_i) / WINDOW_SIZE;

    iter = 0;
    while (z_r * z_r + z_i * z_i <= 4 && iter < data->max_iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + data->julia_r;
        z_i = 2 * tmp * z_i + data->julia_i;
        iter++;
    }
    int color;
    if (iter == data->max_iter)
        color = 0x000000;
    else
        color = get_color(iter, data->max_iter, data->color_shift);

    my_mlx_pixel_put(&data->img, x, y, color);
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
	data->color_shift = 0;  // カラーシフトの初期値
}

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

	// mlxを初期化する
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);

	// 引数を処理する
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

	// ウィンドウを作成する
	data.win = mlx_new_window(data.mlx, WINDOW_SIZE, WINDOW_SIZE, "first window");
	if (data.win == NULL)
	{
		free(data.mlx);
		return (1);
	}

	// img作る
	// 新しいイメージの作成
    data.img.img = mlx_new_image(data.mlx, WINDOW_SIZE, WINDOW_SIZE);
	data.img.addr = mlx_get_data_addr(data.img.img,
                                 &data.img.bits_per_pixel,
                                 &data.img.line_length,
                                 &data.img.endian);

	// 描画
	redraw(&data);

    // 作成したイメージをウィンドウに表示
    mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, X_EVENT, X_MASK, close_window, &data);
	mlx_hook(data.win, EXPOSE_EVENT, EXPOSE_MASK, handle_expose, &data);
	// イベントまち
	mlx_loop(data.mlx);

	// mlxを閉じる

	return (0);
}
