#include <stddef.h>
#include <rlgl.h>

#include "shaders.htmp"
#include "shaders.h"


Shader glow;
int center, inner_radius, outer_radius, fill_color;


Shader lineGradient;
int pointA, pointB, colorA, colorB;
int line_inner_thick, line_outer_thick;

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

    line_inner_thick = GetShaderLocation(lineGradient, "inner_thick");
    line_outer_thick = GetShaderLocation(lineGradient, "outer_thick");
}

void DrawCircleGlow(Vector2 position, float radius_in, float radius_out, Color color)
{
    Vector2 gl_Center = { position.x, GetScreenHeight() - position.y };
    Vector4 gl_Col = {
        color.r / 255.0f,
        color.g / 255.0f,
        color.b / 255.0f,
        color.a / 255.0f,
    };

    SetShaderValue(glow, center, &gl_Center, SHADER_UNIFORM_VEC2);
    SetShaderValue(glow, inner_radius, &radius_in, SHADER_UNIFORM_FLOAT);
    SetShaderValue(glow, outer_radius, &radius_out, SHADER_UNIFORM_FLOAT);
    SetShaderValue(glow, fill_color, &gl_Col, SHADER_UNIFORM_VEC4);

    BeginShaderMode(glow);
    DrawCircleV(position, radius_out, WHITE);
    EndShaderMode();
}

void DrawLineGradientEx(Vector2 startPos, Vector2 endPos, float thick, float glowThick, Color start, Color end)
{
    Vector2 gl_StartPos = startPos;
    gl_StartPos.y = GetScreenHeight() - startPos.y;
    Vector4 gl_ColA = {
        start.r / 255.0f,
        start.g / 255.0f,
        start.b / 255.0f,
        start.a / 255.0f,
    };

    Vector2 gl_EndPos = endPos;
    gl_EndPos.y = GetScreenHeight() - endPos.y;
    Vector4 gl_ColB = {
        end.r / 255.0f,
        end.g / 255.0f,
        end.b / 255.0f,
        end.a / 255.0f,
    };

    SetShaderValue(lineGradient, pointA, &gl_StartPos, SHADER_UNIFORM_VEC2);
    SetShaderValue(lineGradient, pointB, &gl_EndPos, SHADER_UNIFORM_VEC2);
    SetShaderValue(lineGradient, colorA, &gl_ColA, SHADER_UNIFORM_VEC4);
    SetShaderValue(lineGradient, colorB, &gl_ColB, SHADER_UNIFORM_VEC4);

    SetShaderValue(lineGradient, line_inner_thick, &thick, SHADER_UNIFORM_FLOAT);
    SetShaderValue(lineGradient, line_outer_thick, &glowThick, SHADER_UNIFORM_FLOAT);

    BeginShaderMode(lineGradient);
    DrawLineEx(startPos, endPos, glowThick, WHITE);
    EndShaderMode();
}
