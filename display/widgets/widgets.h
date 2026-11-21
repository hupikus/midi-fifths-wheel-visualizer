#ifndef WIDGETS_H
#define WIDGETS_H

struct mouseButton {
    bool pressed;
    bool down;
    bool released;
    bool up;
};

struct mouseState{
    int x;
    int y;

    struct mouseButton left, middle, right;
};

void DrawWidgets(int width, int height);
void WidgetsInput();
#endif // WIDGETS_H
