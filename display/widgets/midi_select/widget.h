#ifndef UI_MIDI_SELECT_H
#define UI_MIDI_SELECT_H
#include "widgets/widgets.h"
#include <stdint.h>

void MidiSelector(int width, int height);
void UI_SetMidiDevice(const char *dev_name, unsigned int dev_port);
void UI_OptimizeMidiList();
void UI_ClearMidiList();

void MidiSelector_ProcessInput(struct mouseState *mouse);

#endif // UI_MIDI_SELECT_H
