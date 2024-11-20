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

	y = 0;
    while (y < WINDOW_SIZE)
    {
        x = 0;
        while (x < WINDOW_SIZE)
        {
            if (x == y)
                my_mlx_pixel_put(&data.img, x, y, 0x00FF0000);  // 赤色
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
