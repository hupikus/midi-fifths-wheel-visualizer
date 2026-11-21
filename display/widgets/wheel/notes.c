#include <math.h>
#include <raylib.h>

#include "widget.h"
#include "shaders.h"

#include "colors.h"
#include "widgets/layout.h"

#include "keys.h"


void DrawNoteGlow(circleTransform t, Color color)
{
    DrawCircleGlow(t.position, t.radius, t.radius * NOTE_GLOW_SCALE, color);
}

Vector2 GetNotePosition(circleTransform t, int order)
{
    double angle = (-M_PI * 0.5) + (M_PI * 2.0) * (order / (float)OCTAVE);
    return (Vector2){
        t.position.x + cos(angle) * t.radius,
        t.position.y + sin(angle) * t.radius,
    };
}

void Notes(circleTransform t)
{
    ClearNotePolygon();
    bool pressed[OCTAVE];
    for (int i = 0; i < OCTAVE; ++i) {
        int note = GetFifthsWheelNote(i);
        pressed[note] = IsNotePressed(note);
        if (pressed[note]) {
            AddToNotePolygon(i);
        }
    }

    NotePolygon(t);

    for (int i = 0; i < OCTAVE; ++i) {
        int note = GetFifthsWheelNote(i);

        circleTransform noteCircle;

        noteCircle.position = GetNotePosition(t, i);
        noteCircle.radius = t.radius * NOTE_RADIUS_SCALE;

        Color col = NOTE_DULL_COLOR;
        if (pressed[note]) {
            col = GetKeyColor(GetHigherPressedKey(note));
            DrawNoteGlow(noteCircle, col);
        }
        DrawCircleSector(noteCircle.position, noteCircle.radius, 0, 360, 100, col);

        if (!pressed[note]) {
            DrawCircleSectorLines(noteCircle.position, noteCircle.radius, 0, 360, 100, NOTE_OUTLINE_COLOR);
        }

        NoteText(noteCircle, note);
    }

}

