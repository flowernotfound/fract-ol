/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:43:41 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/21 18:53:02 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define ERROR_VALUE 42
# define MAX_VAL 1.7e308
# define WINDOW_SIZE 600
# define KEY_ESC 65307
# define X_EVENT 17
# define X_MASK 0L
# define EXPOSE_EVENT 12
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_C 99
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	TRICORN
}					t_fractal_type;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			img;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	int				max_iter;
	t_fractal_type	type;
	double			julia_r;
	double			julia_i;
	int				color_shift;
}					t_data;

int					init_window(t_data *data);
int					init_mlx(t_data *data);
void				init_tricorn(t_data *data);
void				init_julia(t_data *data, double julia_r, double julia_i);
void				init_mandelbrot(t_data *data);

int					close_window(t_data *data);
int					handle_expose(t_data *data);
void				redraw(t_data *data);

void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
void				clean_exit(t_data *data);

int					parse_args(int ac, char **av, t_data *data);
void				print_usage(void);

int					handle_julia_args(int ac, char **av, t_data *data);

char				*process_input(const char *str);
int					is_digit(char c);

double				ft_atof(const char *str);

int					key_hook(int keycode, t_data *data);

int					mouse_hook(int button, int x, int y, t_data *data);

void				move(t_data *data, int direction);

void				zoom(t_data *data, int x, int y, int zoom_in);

void				calculate_mandelbrot(t_data *data, int x, int y);

void				calculate_julia(t_data *data, int x, int y);

void				calculate_tricorn(t_data *data, int x, int y);

int					get_color(int iteration, int max_iteration, int shift);
int					get_pixel_color(int iter, t_data *data);

#endif
