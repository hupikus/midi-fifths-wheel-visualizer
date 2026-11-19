#include <raylib.h>

const int WIDTH = 1200;
const int HEIGHT = 720;
const Color BACKGROUND = { 24, 24, 27, 255 };


int main()
{
    InitWindow(WIDTH, HEIGHT, "VIz");
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BACKGROUND);

        int width = GetRenderWidth();
        int height = GetRenderHeight();


        EndDrawing();
    }

    CloseWindow();
}
