#ifndef COLORS_H
#define COLORS_H
#include <raylib.h>
#include "keys.h"

#define BACKGROUND (Color){ 24, 24, 27, 255 }
#define CIRCLE_COLOR (Color){200, 200, 200, 100}

#define NOTE_OUTLINE_COLOR (Color){175, 175, 175, 255}
#define NOTE_DULL_COLOR (Color){40, 40, 40, 255}

extern Color startColor;
extern Color endColor;

extern Color octaveColors[OCTAVE_COUNT];

void UpdateColors();
Color GetKeyColor(int key);

#endif // COLORS_H
