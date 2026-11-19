#include "keys.h"

bool pressed[128] = {0};

bool IsKeyPressed(int key)
{
    if (key < 0 || key >= MIDI_RANGE) return false;
    return pressed[key];
}

bool IsNotePressed(int note)
{
    if (note < 0 || note >= OCTAVE) return false;
    for (int key = note; key < MIDI_RANGE; key += OCTAVE) {
        if (IsKeyPressed(key)) {
            return true;
        }
    }
    return false;
}

int GetHigherPressedKey(int note)
{
    if (note < 0 || note >= OCTAVE) return false;
    for (int key = MIDI_RANGE - OCTAVE + note; key >= 0; key -= OCTAVE) {
        if (IsKeyPressed(key)) {
            return true;
        }
    }
    return -1;
}

void PressKey(int key)
{
    if (key < 0 || key >= MIDI_RANGE) return;
    pressed[key] = true;
}

void ReleaseKey(int key)
{
    if (key < 0 || key >= MIDI_RANGE) return;
    pressed[key] = false;
}
