#include <raylib.h>
#include "display.h"

int mode = MODE_WHEEL;

float MAX_OCCUPANCY = 0.95;
float MAX_VERTICAL_OCCUPANCY = 0.5;

circleTransform GetCircleTransform(int width, int height)
{
    circleTransform t = {0};

    int occupy_width = width * MAX_OCCUPANCY;
    int occupy_height = height * MAX_OCCUPANCY;
    if (mode == MODE_KEYBOARD) {
        occupy_height *= MAX_VERTICAL_OCCUPANCY;
    }

    if (occupy_width < occupy_height) {
        t.radius = occupy_width / 2.0;
    } else {
        t.radius = occupy_height / 2.0;
    }

    t.position.x = width / 2;
    t.position.y = height * (1.0 - MAX_OCCUPANCY) / 2 + t.radius;

    return t;
}


const Color CIRCLE_COLOR = { 222, 222, 222, 222};

void Circle(circleTransform t)
{
    DrawCircleV(t.position, t.radius, CIRCLE_COLOR);
}
