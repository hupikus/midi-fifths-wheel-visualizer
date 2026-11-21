#include "widgets.h"

#include "wheel/widget.h"
#include "midi_select/widget.h"

void DrawWidgets(int width, int height)
{
    Wheel(width, height);
    MidiSelector();
}
