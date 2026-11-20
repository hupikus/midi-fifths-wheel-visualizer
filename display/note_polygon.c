#include "display.h"

#include "options.h"
#include "colors.h"

#include "keys.h"
#include "shaders.h"

int points_size = 0;
int points[OCTAVE] = {0};

void ClearNotePolygon()
{
    points_size = 0;
}

void AddToNotePolygon(int order)
{
    if (order < 0 || order >= OCTAVE) return;

    points[points_size++] = order;
    if (points_size >= OCTAVE) return;
}

void NotePolygon(circleTransform t)
{
    if (points_size < 3) return;

    for (int i = 0; i < points_size; ++i) {
        int j = (i + 1) % points_size;

        Vector2 posA = GetNotePosition(t, points[i]);
        int noteA = GetFifthsWheelNote(points[i]);
        Color colA = GetKeyColor(GetHigherPressedKey(noteA));

        Vector2 posB = GetNotePosition(t, points[j]);
        int noteB = GetFifthsWheelNote(points[j]);
        Color colB = GetKeyColor(GetHigherPressedKey(noteB));

        float relScale = t.radius / CIRCLE_DEFAULT_RADIUS;
        float thick = NOTE_POLYGON_THICKNESS * relScale;
        float glowThick = thick + NOTE_POLYGON_GLOW_THICKNESS * relScale;
        
        DrawLineGradientEx(posA, posB, thick, glowThick, colA, colB);
    }
}
