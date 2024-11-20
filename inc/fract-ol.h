#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include <stdlib.h>

// for debug
# include <stdio.h>

# define WINDOW_SIZE 600
// キーコードはどのライブラリ使うかによって変わる
// 今はminilibx-linuxを使ってるからこうなる　mac用のものでコンパイルすると個々変える必要ある
# define KEY_ESC 65307
# define X 120

typedef struct s_img {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_img;

typedef struct s_data {
    void    *mlx;
    void    *win;
	t_img   img;
	double  min_r;      // 実部のmin
    double  max_r;      // 実部のmax
    double  min_i;      // 虚部のmin
    double  max_i;      // 虚部のmax
    int     max_iter;   // 発散判定の上限回数
} t_data;

int key_hook(int keycode, t_data *data);
int close_window(t_data *data);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
