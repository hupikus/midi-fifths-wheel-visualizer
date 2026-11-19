#include "colors.h"

Color octaveColors[OCTAVE_COUNT] = {0};

Color GetKeyColor(int key)
{
    int octave = key / OCTAVE;
    if (octave < OCTAVE_COUNT && false) {
        return octaveColors[octave];
    }
    return PINK;
}
