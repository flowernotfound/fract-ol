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

typedef struct s_data {
    void    *mlx;
    void    *win;
} t_data;

int key_hook(int keycode, t_data *data);
int close_window(t_data *data);

#endif
