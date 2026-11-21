#include <stdbool.h>
#include <raylib.h>

#include "widgets.h"
#include "layout.h"

#include "wheel/widget.h"
#include "midi_select/widget.h"

void DrawWidgets(int width, int height)
{
    Wheel(width, height);
    MidiSelector(width, height);
}

struct mouseState mouse = {0};

void WidgetsInput()
{
    mouse.x = GetMouseX();
    mouse.y = GetMouseY();

    mouse.left.pressed = IsMouseButtonPressed(0);
    mouse.left.down = IsMouseButtonDown(0);
    mouse.left.released = IsMouseButtonReleased(0);
    mouse.left.up = IsMouseButtonUp(0);

    //mouse.middle.pressed = IsMouseButtonPressed(1);
    //mouse.middle.down = IsMouseButtonDown(1);
    //mouse.middle.released = IsMouseButtonReleased(1);
    //mouse.middle.up = IsMouseButtonUp(1);

    //mouse.right.pressed = IsMouseButtonPressed(2);
    //mouse.right.down = IsMouseButtonDown(2);
    //mouse.right.released = IsMouseButtonReleased(2);
    //mouse.right.up = IsMouseButtonUp(2);

    MidiSelector_ProcessInput(&mouse);
}
