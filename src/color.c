#include "../inc/fract-ol.h"

int get_color(int iteration, int max_iteration, int shift)
{
    if (iteration == max_iteration)
        return (0x000000); // 発散しないとこは普通に黒
    // 0xFF0000を基準に回転してるだけ
    return ((iteration * 0xFF0000 / max_iteration + shift) & 0xFFFFFF);
}
