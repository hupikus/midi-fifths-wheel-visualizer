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

void MidiSelector(int width, int height)
{
    DrawRectangle(width * UI_MARGIN, height * UI_MARGIN, SIDE_BUTTON_WIDTH, SIDE_BUTTON_HEIGHT, UI_PANEL_COLOR);
    DrawRectangle(width * UI_MARGIN, height * UI_MARGIN, SIDE_BUTTON_WIDTH, SIDE_BUTTON_HEIGHT, UI_PANEL_OUTLINE_COLOR);
}

void MidiSelector_ProcessInput(struct mouseState *mouse)
{
}
