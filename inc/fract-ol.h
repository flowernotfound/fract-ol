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
	double  min_r;
    double  max_r;
    double  min_i;
    double  max_i;
    int     max_iter;
	t_fractal_type type;
    double  julia_r;
    double  julia_i;
	int     color_shift;
} t_data;

// init.c
int	init_window(t_data *data);
int	init_mlx(t_data *data);
void	init_tricorn(t_data *data);
void	init_julia(t_data *data, double julia_r, double julia_i);
void	init_mandelbrot(t_data *data);

// events.c
int close_window(t_data *data);
int handle_expose(t_data *data);
void redraw(t_data *data);

// utils.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	clean_exit(t_data *data);

// parse_args.c
int	parse_args(int ac, char **av, t_data *data);
void	print_usage(void);

// parse_julia.c
int	handle_julia_args(int ac, char **av, t_data *data);

// process_input.c
char	*process_input(const char *str);
int	is_digit(char c);

// atof.c
double	ft_atof(const char *str);

// key.c
int	key_hook(int keycode, t_data *data);

// mouse.c
int	mouse_hook(int button, int x, int y, t_data *data);

// move.c
void    move(t_data *data, int direction);

// zoom.c
void    zoom(t_data *data, int x, int y, int zoom_in);

// mandelbrot.c
void    calculate_mandelbrot(t_data *data, int x, int y);

// julia.c
void	calculate_julia(t_data *data, int x, int y);

// tricorn.c
void    calculate_tricorn(t_data *data, int x, int y);

// color.c
int	get_color(int iteration, int max_iteration, int shift);

#endif
