#include "colors.h"
#include <assert.h>


Color startColor = ORANGE;
Color endColor = PINK;

Color octaveColors[OCTAVE_COUNT] = {0};

void UpdateColors()
{
    if (OCTAVE_COUNT <= 1) {
        octaveColors[0] = startColor;
        return;
    }

    Color c = startColor;
    Color step = {
        ((int)endColor.r - (int)startColor.r) / (OCTAVE_COUNT - 1),
        ((int)endColor.g - (int)startColor.g) / (OCTAVE_COUNT - 1),
        ((int)endColor.b - (int)startColor.b) / (OCTAVE_COUNT - 1),
        ((int)endColor.a - (int)startColor.a) / (OCTAVE_COUNT - 1)
    };

    for (int i = 0; i < OCTAVE_COUNT; ++i) {
        octaveColors[i] = c;

        c.r += step.r;
        c.g += step.g;
        c.b += step.b;
        c.a += step.a;
    }
}

Color GetKeyColor(int key)
{
    if (key < 0 || key >= MIDI_RANGE) return BEIGE;

    int octave = key / OCTAVE;
    if (octave < OCTAVE_COUNT) {
        return octaveColors[octave];
    }
    return BEIGE;
}
