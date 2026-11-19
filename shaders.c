#include <stddef.h>
#include "rlgl.h"

#include "shaders.h"

Shader glow;

int center, inner_radius, outer_radius, fill_color;

void InitShaders()
{
    glow = LoadShader(NULL, "shaders/glow.glsl");

    center = GetShaderLocation(glow, "center");
    inner_radius = GetShaderLocation(glow, "inner_radius");
    outer_radius = GetShaderLocation(glow, "outer_radius");
    fill_color = GetShaderLocation(glow, "color");
}

void DrawCircleGlow(Vector2 position, float radius_in, float radius_out, Color color)
{
    BeginShaderMode(glow);

    Vector2 gl_Center = { position.x, GetScreenHeight() - position.y };
    Vector4 gl_Col = {
        color.r / 255.0,
        color.g / 255.0,
        color.b / 255.0,
        color.a / 255.0,
    };

    SetShaderValue(glow, center, &gl_Center, SHADER_UNIFORM_VEC2);
    SetShaderValue(glow, inner_radius, &radius_in, SHADER_UNIFORM_FLOAT);
    SetShaderValue(glow, outer_radius, &radius_out, SHADER_UNIFORM_FLOAT);
    SetShaderValue(glow, fill_color, &gl_Col, SHADER_UNIFORM_VEC4);

    DrawCircleV(position, radius_out, WHITE);
    EndShaderMode();
}
