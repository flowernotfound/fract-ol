// parse.c
#include "../inc/fract-ol.h"

void print_usage(void)
{
    printf("Usage: ./fractol <type> [julia_r julia_i]\n");
    printf("type: mandelbrot or julia or tricorn\n");
    printf("\nExamples:\n");
    printf("  ./fractol mandelbrot\n");
    printf("  ./fractol julia 0.285 0.01\n");
    printf("  ./fractol tricorn\n");
    printf("\nJulia set parameters:\n");
    printf("  - Must be numbers between -2.0 and 2.0\n");
    printf("  - Examples of valid parameters:\n");
    printf("    0.285 0.01\n");
    printf("    -0.4 0.6\n");
    printf("    0.0 -0.8\n");
}

int handle_fractal_type(int ac, char **av, t_data *data)
{
    if (strcmp(av[1], "mandelbrot") == 0)
    {
        init_mandelbrot(data);
        return (0);
    }
    if (strcmp(av[1], "julia") == 0)
        return (handle_julia_args(ac, av, data));
    if (strcmp(av[1], "tricorn") == 0)
    {
        init_tricorn(data);
        return (0);
    }
    printf("Invalid fractal type\n");
    print_usage();
    return (1);
}

int parse_args(int ac, char **av, t_data *data)
{
    if (ac < 2)
    {
        print_usage();
        return (1);
    }
    return (handle_fractal_type(ac, av, data));
}
