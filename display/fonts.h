#ifndef FONTS_H
#define FONTS_H
#include <raylib.h>

extern Font default_font;
extern Font note_font;

void InitFonts();
void GenerateNoteFont(float size);

#endif
