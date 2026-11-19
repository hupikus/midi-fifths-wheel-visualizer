#ifndef KEYS_H
#define KEYS_H
#include <stdbool.h>

#define C 0
#define Db 1
#define D 2
#define Eb 3
#define E 4
#define F 5
#define Gb 6
#define G 7
#define Ab 8
#define A 9
#define Bb 10
#define B 11

#define MIDI_RANGE 128
#define OCTAVE 12
#define OCTAVE_COUNT MIDI_RANGE / OCTAVE + 1

static_assert(OCTAVE_COUNT > 0);

extern bool pressed[128];

bool IsKeyPressed(int key);
bool IsNotePressed(int note);

int GetHigherPressedKey(int note);

void PressKey(int key);
void ReleaseKey(int key);

const char *GetNoteName(int note);
int GetFifthsWheelNote(int order);

#endif // KEYS_H
