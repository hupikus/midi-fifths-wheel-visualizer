#include <stddef.h>
#include "rlgl.h"

#include "shaders.h"

Shader glow;

void InitShaders()
{
    glow = LoadShader(NULL, "shaders/glow.glsl");
}

void DrawCircleGlow(Vector2 position, float radius_in, float radius_out, Color color)
{
    BeginShaderMode(glow);
    DrawCircleLinesEx(position, radius_out, (radius_out - radius_in), color);
    EndShaderMode();
}
