#ifndef UI_WHEEL_H
#define UI_WHEEL_H
#include <raylib.h>

typedef struct {
	Vector2 position;
	float radius;
} circleTransform;

circleTransform GetCircleTransform(int width, int height);
void Circle(circleTransform t);
void Notes(circleTransform t);
Vector2 GetNotePosition(circleTransform t, int order);

void NoteText(circleTransform t, int note);

void ClearNotePolygon();
void AddToNotePolygon(int order);
void NotePolygon(circleTransform t);

#endif // UI_WHEEL_H
