#include "../inc/fract-ol.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

char *process_input(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
        if (!str[i] || !is_digit(str[i]))
            return (NULL);
    }
    else if (!is_digit(str[i]))
        return (NULL);
    while (str[i])
    {
        if (str[i] == '.')
        {
            i++;
            if (!str[i] || !is_digit(str[i]))
                return (NULL);
        }
        else if (!is_digit(str[i]))
            return (NULL);
        i++;
    }
    return ((char *)str);
}
