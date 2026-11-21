#ifndef WIDGETS_H
#define WIDGETS_H

struct mouseButton {
    bool pressed;
    bool down;
    bool released;
    bool up;
};

struct mouseState {
    int x;
    int y;

    struct mouseButton left, middle, right;
};

void Widgets_Layout(int width, int height);
void Widgets_Draw();
void Widgets_Input();
#endif // WIDGETS_H
