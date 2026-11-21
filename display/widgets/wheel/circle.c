#include <raylib.h>

#include "widget.h"
#include "colors.h"
#include "widgets/layout.h"


circleTransform GetCircleTransform(int width, int height)
{
    circleTransform t = {0};

    int occupy_width = width * WHEEL_MAX_OCCUPANCY;
    int occupy_height = height * WHEEL_MAX_OCCUPANCY;
    if (mode == MODE_KEYBOARD) {
        occupy_height *= WHEEL_MAX_VERTICAL_OCCUPANCY;
    }

    if (occupy_width < occupy_height) {
        t.radius = occupy_width / 2.0;
    } else {
        t.radius = occupy_height / 2.0;
    }


    t.radius *= (1.0 - NOTE_RADIUS_SCALE);
    t.position.x = width / 2;
    t.position.y = height * (1.0 - WHEEL_MAX_OCCUPANCY) / 2 + t.radius * (1.0 + NOTE_RADIUS_SCALE);


    return t;
}


void Circle(circleTransform t)
{
    DrawCircleSectorLines(t.position, t.radius, 0, 360, 360, CIRCLE_COLOR);
}
