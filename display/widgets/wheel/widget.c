#include "widget.h"

void Wheel(int width, int height)
{
    circleTransform transform = GetCircleTransform(width, height);
    Circle(transform);
    Notes(transform);
}
