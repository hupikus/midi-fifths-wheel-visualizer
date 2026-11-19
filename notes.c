#include <math.h>
#include <raylib.h>

#include "shaders.h"
#include "display.h"
#include "colors.h"
#include "options.h"

#include "keys.h"


void DrawNoteGlow(circleTransform t, Color color)
{
    DrawCircleGlow(t.position, t.radius, t.radius * NOTE_GLOW_SCALE, color);
}


#define COUNT 12
void Notes(circleTransform t)
{
    PressKey(15);
    double angle = 0.0;
    for (int note = 0; note <= COUNT; ++note) {

        circleTransform noteCircle;

        noteCircle.position = t.position;
        noteCircle.position.x += cos(angle) * t.radius;
        noteCircle.position.y += sin(angle) * t.radius;
        noteCircle.radius = t.radius * NOTE_RADIUS_SCALE;

        bool pressed = IsNotePressed(note);
        Color col = NOTE_DULL_COLOR;
        if (pressed) {
            col = GetKeyColor(GetHigherPressedKey(note));
            DrawNoteGlow(noteCircle, col);
        }
        DrawCircleSector(noteCircle.position, noteCircle.radius, 0, 360, 100, col);

        if (!pressed) {
            DrawCircleSectorLines(noteCircle.position, noteCircle.radius, 0, 360, 100, NOTE_OUTLINE_COLOR);
        }

        angle = M_PI * 2.0 / (float)COUNT * note;
    }
}

