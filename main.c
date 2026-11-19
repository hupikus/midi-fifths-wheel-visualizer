#include <raylib.h>

#include "shaders.h"
#include "fonts.h"

#include "colors.h"
#include "display.h"

#define WIDTH 1200
#define HEIGHT 720

#if __STDC_VERSION__ < 202311L
#define static_assert _Static_assert
#endif

int main()
{
    InitWindow(WIDTH, HEIGHT, "VIz");
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitShaders();
    InitFonts();
    UpdateColors();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BACKGROUND);

        int width = GetRenderWidth();
        int height = GetRenderHeight();

        circleTransform transform = GetCircleTransform(width, height);
        Circle(transform);
        Notes(transform);

        EndDrawing();
    }

    CloseWindow();
}
