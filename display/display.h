#ifndef DISPLAY_H
#define DISPLAY_H

typedef struct {
	Vector2 position;
	float radius;
} circleTransform;

circleTransform GetCircleTransform(int width, int height);
void Circle(circleTransform t);
void Notes(circleTransform t);

#endif // DISPLAY_H
