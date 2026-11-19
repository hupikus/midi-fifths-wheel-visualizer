#ifndef DISPLAY_H
#define DISPLAY_H

enum { MODE_WHEEL, MODE_KEYBOARD, MODE_TRANSITIONING};
typedef struct {
	Vector2 position;
	float radius;
} circleTransform;

circleTransform GetCircleTransform(int width, int height);
void Circle(circleTransform t);

#endif // DISPLAY_H
