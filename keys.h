#ifndef KEYS_H
#define KEYS_H
#include <stdbool.h>

#define MIDI_RANGE 128
#define OCTAVE 12
#define OCTAVE_COUNT MIDI_RANGE / OCTAVE + 1

extern bool pressed[128];

bool IsKeyPressed(int key);
bool IsNotePressed(int note);

int GetHigherPressedKey(int note);


void PressKey(int key);
void ReleaseKey(int key);

#endif // KEYS_H
