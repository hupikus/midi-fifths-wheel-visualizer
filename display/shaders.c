#include <stddef.h>
#include <rlgl.h>

#include "shaders.htmp"
#include "shaders.h"


Shader glow;
int center, inner_radius, outer_radius, fill_color;

Shader lineGradient;
int pointA, pointB, colorA, colorB;

void InitShaders()
{
    glow = LoadShaderFromMemory(NULL, radial_glow_shader);

    center = GetShaderLocation(glow, "center");
    inner_radius = GetShaderLocation(glow, "inner_radius");
    outer_radius = GetShaderLocation(glow, "outer_radius");
    fill_color = GetShaderLocation(glow, "color");

    lineGradient = LoadShaderFromMemory(NULL, line_gradient_shader);

    pointA = GetShaderLocation(lineGradient, "pointA");
    pointB = GetShaderLocation(lineGradient, "pointB");
    colorA = GetShaderLocation(lineGradient, "colorA");
    colorB = GetShaderLocation(lineGradient, "colorB");
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

void DrawLineGradientEx(Vector2 startPos, Vector2 endPos, float thick, Color start, Color end)
{
    BeginShaderMode(lineGradient);

    Vector4 gl_ColA = {
        start.r / 255.0,
        start.g / 255.0,
        start.b / 255.0,
        start.a / 255.0,
    };

    Vector4 gl_ColB = {
        end.r / 255.0,
        end.g / 255.0,
        end.b / 255.0,
        end.a / 255.0,
    };

    SetShaderValue(lineGradient, pointA, &startPos, SHADER_UNIFORM_VEC2);
    SetShaderValue(lineGradient, pointB, &endPos, SHADER_UNIFORM_VEC2);
    SetShaderValue(lineGradient, colorA, &gl_ColA, SHADER_UNIFORM_VEC4);
    SetShaderValue(lineGradient, colorB, &gl_ColB, SHADER_UNIFORM_VEC4);

    DrawLineEx(startPos, endPos, thick, WHITE);
    
    EndShaderMode();
}
