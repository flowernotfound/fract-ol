#include "../inc/fract-ol.h"

int main(void)
{
	t_data data;

	// mlxを初期化する
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);

	// 引数を処理する
	// ウィンドウを作成する
	data.win = mlx_new_window(data.mlx, WINDOW_SIZE, WINDOW_SIZE, "first window");
	// イベントまち
	mlx_loop(data.mlx);
	// ウィンドウを閉じる
	// mlxを閉じる

	return (0);
}
