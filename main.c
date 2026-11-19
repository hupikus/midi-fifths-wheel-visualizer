#include <raylib.h>

#include "shaders.h"
#include "colors.h"
#include "display.h"

#define WIDTH 1200
#define HEIGHT 720

int main()
{
    InitWindow(WIDTH, HEIGHT, "VIz");
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitShaders();

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
