#include "keys.h"

bool keys_pressed[128] = {0};

bool IsKeyPressed(int key)
{
    if (key < 0 || key >= MIDI_RANGE) return false;
    return keys_pressed[key];
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
    if (note < 0 || note >= OCTAVE) return -1;
    for (int key = (OCTAVE_COUNT - 1) * OCTAVE + note; key >= 0; key -= OCTAVE) {
        if (IsKeyPressed(key)) {
            return key;
        }
    }
    return -1;
}

void PressKey(int key)
{
    if (key < 0 || key >= MIDI_RANGE) return;
    keys_pressed[key] = true;
}

void ReleaseKey(int key)
{
    if (key < 0 || key >= MIDI_RANGE) return;
    keys_pressed[key] = false;
}

const char *notes[OCTAVE] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const char *GetNoteName(int note)
{
    if (note < 0 || note >= OCTAVE) return "Cb";
    return notes[note];
}

const int fifths_wheel[OCTAVE] = {F, C, G, D, A, E, B, Gb, Db, Ab, Eb, Bb};
int GetFifthsWheelNote(int order)
{
    if (order < 0 || order >= OCTAVE) return -1;
    return fifths_wheel[order];
}
