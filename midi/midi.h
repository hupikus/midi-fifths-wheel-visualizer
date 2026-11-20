#ifndef MIDI_H
#define MIDI_H
#include <stdbool.h>

extern bool midi_error;
void *InitMidi(void *arg);

void TerminateMidi();

#endif // MIDI_H
