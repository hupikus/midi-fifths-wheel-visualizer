#include <pthread.h>
#include <raylib.h>

#include "shaders.h"
#include "fonts.h"

#include "colors.h"
#include "display/widgets/layout.h"
#include "display/widgets/widgets.h"

#include "midi/midi.h"


#if __STDC_VERSION__ < 202311L
#define static_assert _Static_assert
#endif

int main()
{
    InitWindow(WIDTH, HEIGHT, "VIz");
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    pthread_t midiThread;
    pthread_create(
        &midiThread,
        NULL,
        InitMidi,
        NULL
    );

    InitShaders();
    InitFonts();
    UpdateColors();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BACKGROUND);

        int width = GetRenderWidth();
        int height = GetRenderHeight();

        Widgets_Layout(width, height);
        Widgets_Draw();
        Widgets_Input();

        EndDrawing();
    }

    CloseWindow();
    TerminateMidi();
}
