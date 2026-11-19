#include "display.h"

#include "options.h"
#include "keys.h"
#include "shaders.h"

int points_size = 0;
Vector2 points[OCTAVE] = {0};

void ClearNotePolygon()
{
    points_size = 0;
}

void AddToNotePolygon(Vector2 position)
{
    points[points_size++] = position;
    if (points_size >= OCTAVE) return;
}

void NotePolygon()
{
    if (points_size < 3) return;

    for (int i = 0; i < points_size; ++i) {
        int j = (i + 1) % points_size;
        DrawLineGradientEx(points[i], points[j], NOTE_POLYGON_THICKNESS, PINK, ORANGE);
    }
}
