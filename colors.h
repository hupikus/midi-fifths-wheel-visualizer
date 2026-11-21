#ifndef COLORS_H
#define COLORS_H
#include <raylib.h>
#include "keys.h"

#define BACKGROUND (Color){ 24, 24, 27, 255 }
#define CIRCLE_COLOR (Color){200, 200, 200, 100}

#define NOTE_TEXT_COLOR (Color){225, 225, 225, 255}
#define NOTE_OUTLINE_COLOR (Color){175, 175, 175, 255}
#define NOTE_DULL_COLOR (Color){40, 40, 40, 255}

#define UI_PANEL_COLOR (Color){40, 40, 40, 255}
#define UI_PANEL_OUTLINE_COLOR (Color){200, 200, 200, 100}

extern Color startColor;
extern Color endColor;

extern Color octaveColors[OCTAVE_COUNT];

void UpdateColors();
Color GetKeyColor(int key);

#endif // COLORS_H
