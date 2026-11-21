#include <stdbool.h>
#include <stddef.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <raylib.h>

#include "widget.h"
#include "widgets/layout.h"
#include "colors.h"

bool selected = false;
bool pressed = true;

Rectangle btn;

void MidiSelector_Layout(int width, int height)
{
    btn = (Rectangle){
        width * UI_MARGIN,
        width * UI_MARGIN,
        SIDE_BUTTON_WIDTH,
        SIDE_BUTTON_HEIGHT
    };
}

void MidiSelector_Draw(void)
{
    Color col = UI_PANEL_COLOR;
    if (selected) {
        col = UI_PANEL_SELECTED_COLOR;
        if (pressed) {
            col = UI_PANEL_PRESSED_COLOR;
        }
    }
    DrawRectangleRec(btn, col);
    DrawRectangleRec(btn, UI_PANEL_OUTLINE_COLOR);
}

void MidiSelector_Input(struct mouseState *mouse)
{
    selected = false;
    pressed = false;

    if (mouse->x <= btn.x) { return; }
    if (mouse->x >= btn.x + btn.width) { return; }
    if (mouse->y <= btn.y) { return; }
    if (mouse->x >= btn.y + btn.height) { return; }

    selected = true;
    pressed = mouse->left.pressed;
}
