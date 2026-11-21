#include "widget.h"

circleTransform transform;

void Wheel_Layout(int width, int height)
{
    transform = GetCircleTransform(width, height);
}

void Wheel_Draw()
{
    Circle(transform);
    Notes(transform);
}

void Wheel_Input(struct mouseState *mouse)
{
}
