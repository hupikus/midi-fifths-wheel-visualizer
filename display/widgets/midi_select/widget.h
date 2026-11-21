#ifndef UI_MIDI_SELECT_H
#define UI_MIDI_SELECT_H
#include "widgets/widgets.h"
#include <stdint.h>

void MidiSelector_Layout(int width, int height);
void MidiSelector_Draw();
void MidiSelector_Input(struct mouseState *mouse);

void UI_SetMidiDevice(const char *dev_name, unsigned int dev_port);
void UI_OptimizeMidiList();
void UI_ClearMidiList();


#endif // UI_MIDI_SELECT_H
