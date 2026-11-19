#include <stddef.h>
#include "shaders.h"

Shader glow;

void InitShaders()
{
    glow = LoadShader(NULL, "shaders/glow.fs");
}
