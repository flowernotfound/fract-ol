#include "../inc/fract-ol.h"

int key_hook(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
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
    if (iter == data->max_iter)
        my_mlx_pixel_put(&data->img, x, y, 0x000000);
    else
    {
        int color = (iter * 0xFF0000 / data->max_iter) & 0xFF0000;
        my_mlx_pixel_put(&data->img, x, y, color);
    }
}

void    init_mandelbrot(t_data *data)
{
    data->min_r = -2.0;
    data->max_r = 1.0;
    data->min_i = -1.5;
    data->max_i = 1.5;
    data->max_iter = 200;
}

int main(void)
{
	t_data data;
	int x;
	int y;

	// mlxを初期化する
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);

	// 引数を処理する

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

    // まmんでるぶろの初期化
    init_mandelbrot(&data);

    // フラクタル描画する
    y = 0;
    while (y < WINDOW_SIZE)
    {
        x = 0;
        while (x < WINDOW_SIZE)
        {
            calculate_mandelbrot(&data, x, y);
            x++;
        }
        y++;
    }

    // 作成したイメージをウィンドウに表示
    mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);

	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, X, 0, close_window, &data);

	// イベントまち
	mlx_loop(data.mlx);

	// mlxを閉じる

	return (0);
}
