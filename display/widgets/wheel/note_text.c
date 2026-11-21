#include <math.h>

#include "widget.h"
#include "fonts.h"
#include "colors.h"

#define RELOAD_TRESHOLD 2.0
#define FONT_SCALE 0.93
#define MIN_NOTE_FONT_SIZE 11.0
float lastSize = 0.0;
void NoteText(circleTransform t, int note)
{
    const char *text = GetNoteName(note);
    float size = fmaxf(t.radius * FONT_SCALE, MIN_NOTE_FONT_SIZE);

    if (fabs(size - lastSize) > RELOAD_TRESHOLD) {
        GenerateNoteFont(size);
        lastSize = size;
    }

    float scale = size / note_font.baseSize;

    int index = GetGlyphIndex(note_font, text[0]);
    GlyphInfo glyph = note_font.glyphs[index];
    float offsetY = glyph.offsetY;

    Vector2 fontDimensions = MeasureTextEx(note_font, text, size, 0);
    fontDimensions.y = note_font.recs[index].height * scale;

    float verticalOffset = (fontDimensions.y - size) * 0.5f;
    Vector2 pos = {
        t.position.x - fontDimensions.x * 0.5f,
        t.position.y - fontDimensions.y * 0.5f - offsetY,
    };


    DrawTextEx(note_font, text, pos, size, 0, NOTE_TEXT_COLOR);
}
