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

void AddToNotePolygon(int note)
{
    if (note < 0 || note >= OCTAVE) return;

    points[points_size++] = note;
    if (points_size >= OCTAVE) return;
}

void NotePolygon(circleTransform t)
{
    if (points_size < 3) return;

    for (int i = 0; i < points_size; ++i) {
        int j = (i + 1) % points_size;

        Vector2 posA = GetNotePosition(t, points[i]);
        Color colA = GetKeyColor(GetHigherPressedKey(points[i]));

        Vector2 posB = GetNotePosition(t, points[j]);
        Color colB = GetKeyColor(GetHigherPressedKey(points[j]));
        
        DrawLineGradientEx(posA, posB, NOTE_POLYGON_THICKNESS, colA, colB);
        DrawLineGradientEx(posA, posB, NOTE_POLYGON_THICKNESS, colA, colB);
    }
}
