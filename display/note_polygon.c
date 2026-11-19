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
        int noteA = GetFifthsWheelNote(i);
        Color colA = GetKeyColor(GetHigherPressedKey(noteA));

        Vector2 posB = GetNotePosition(t, points[j]);
        int noteB = GetFifthsWheelNote(j);
        Color colB = GetKeyColor(GetHigherPressedKey(noteB));
        
        DrawLineGradientEx(posA, posB, NOTE_POLYGON_THICKNESS, colA, colB);
        DrawLineGradientEx(posA, posB, NOTE_POLYGON_THICKNESS, colA, colB);
    }
}
