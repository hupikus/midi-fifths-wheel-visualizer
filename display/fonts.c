#include <stddef.h>

#include "fonts.h"

Font default_font;
Font note_font;

void InitFonts()
{
    default_font = LoadFont("assets/Spicy Sauce.ttf");
    GenerateNoteFont(32.0);
}

void GenerateNoteFont(float size)
{
    note_font = LoadFontEx("assets/Spicy Sauce.ttf", size, NULL, 0);
}
