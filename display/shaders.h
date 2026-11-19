#ifndef SHADERS_H
#define SHADERS_H
#include <raylib.h>

void InitShaders();

void DrawCircleGlow(Vector2 position, float radius_in, float radius_out, Color color);
void DrawLineGradientEx(Vector2 startPos, Vector2 endPos, float thick, Color colorA, Color colorB);

#endif // SHADERS_H
