#include "../inc/fract-ol.h"

int get_color(int iteration, int max_iteration, int shift)
{
    if (iteration == max_iteration)
        return (0x000000);
    return ((iteration * 0xFF0000 / max_iteration + shift) & 0xFFFFFF);
}
