#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include <stdlib.h>
#include <errno.h>
#include <limits.h>

// for debug
# include <stdio.h>
# include <string.h>

#define ERROR_VALUE 42
#define MAX_VAL 1.7e308
# define WINDOW_SIZE 600
// キーコードはどのライブラリ使うかによって変わる
// 今はminilibx-linuxを使ってるからこうなる　mac用のものでコンパイルすると個々変える必要ある
# define KEY_ESC 65307
# define X_EVENT 17
# define X_MASK 0L
# define EXPOSE_EVENT 12
# define EXPOSE_MASK (1L<<15)
// 矢印
# define KEY_UP      65362
# define KEY_DOWN    65364
# define KEY_LEFT    65361
# define KEY_RIGHT   65363
# define KEY_C 99
// マウス
# define SCROLL_UP    4
# define SCROLL_DOWN  5

// 図形の種類
typedef enum e_fractal_type {
    MANDELBROT,
    JULIA,
	TRICORN
} t_fractal_type;

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
	t_fractal_type type;   // 種類
    double  julia_r;       // ジュリア集合用
    double  julia_i;
	int     color_shift;
} t_data;

int key_hook(int keycode, t_data *data);
int    mouse_hook(int button, int x, int y, t_data *data);
int handle_expose(t_data *data);
int close_window(t_data *data);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
void    zoom(t_data *data, int x, int y, int zoom_in);
void    move(t_data *data, int direction);
void    redraw(t_data *data);
int close_window(t_data *data);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
void    calculate_mandelbrot(t_data *data, int x, int y);
void    init_mandelbrot(t_data *data);
void    calculate_julia(t_data *data, int x, int y);
void    init_julia(t_data *data, double julia_r, double julia_i);
int     create_rgb(int r, int g, int b);
int get_color(int iteration, int max_iteration, int shift);
void    calculate_tricorn(t_data *data, int x, int y);
void    init_tricorn(t_data *data);
void	clean_exit(t_data *data);
void	print_usage(void);
int	parse_args(int ac, char **av, t_data *data);
int	init_mlx(t_data *data);
int	init_window(t_data *data);
void	setup_hooks(t_data *data);
void print_usage(void);
int parse_julia_param(const char *str, double *value);
int check_julia_range(double value);
int parse_args(int ac, char **av, t_data *data);
int handle_julia_args(int ac, char **av, t_data *data);
int handle_fractal_type(int ac, char **av, t_data *data);

double ft_atof(const char *str);
char *process_input(const char *str);
int is_digit(char c);

#endif
