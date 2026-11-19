#include <math.h>
#include <raylib.h>

#include "display.h"
#include "options.h"


#define COUNT 12
void Notes(circleTransform t)
{
    double angle = 0.0;
    float radius = t.radius * NOTE_RADIUS_SCALE;
    for (int n = 0; n <= COUNT; ++n) {
        Vector2 pos = t.position;
        pos.x += cos(angle) * t.radius;
        pos.y += sin(angle) * t.radius;

        DrawCircleSector(pos, radius, 0, 360, 100, RAYWHITE);

        angle = M_PI * 2.0 / (float)COUNT * n;
    }
}
