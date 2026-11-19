#ifndef DISPLAY_H
#define DISPLAY_H
#include <raylib.h>

typedef struct {
	Vector2 position;
	float radius;
} circleTransform;

circleTransform GetCircleTransform(int width, int height);
void Circle(circleTransform t);
void Notes(circleTransform t);
void NoteText(circleTransform t, int note);

void ClearNotePolygon();
void AddToNotePolygon(Vector2 position);
void NotePolygon();

#endif // DISPLAY_H
