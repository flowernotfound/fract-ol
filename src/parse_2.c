#include "../inc/fract-ol.h"

int parse_julia_param(const char *str, double *value)
{
    char    *endptr;
    double  tmp;

    errno = 0;
    tmp = strtod(str, &endptr);
    if (errno == ERANGE)
    {
        printf("Parameter out of range\n");
        return (0);
    }
    if (*endptr != '\0')
    {
        printf("Invalid character in parameter\n");
        return (0);
    }
    if (!check_julia_range(tmp))
    {
        printf("Parameter must be between -2.0 and 2.0\n");
        return (0);
    }
    *value = tmp;
    return (1);
}

int check_julia_range(double value)
{
    return (value >= -2.0 && value <= 2.0);
}

int handle_julia_args(int ac, char **av, t_data *data)
{
    double julia_i;
    double julia_r;

    if (ac != 4)
    {
        printf("Julia set requires 2 parameters\n");
        print_usage();
        return (1);
    }
    if (!parse_julia_param(av[2], &julia_r))
    {
        printf("Invalid first parameter for Julia set\n");
        return (1);
    }
    if (!parse_julia_param(av[3], &julia_i))
    {
        printf("Invalid second parameter for Julia set\n");
        return (1);
    }
    init_julia(data, julia_r, julia_i);
    return (0);
}
