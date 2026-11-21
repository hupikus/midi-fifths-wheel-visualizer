#ifndef LAYOUT_H
#define LAYOUT_H

#define WIDTH 1200
#define HEIGHT 720

#define MODE_WHEEL 0
#define MODE_KEYBOARD 1
#define MODE_TRANSITION -1
extern int mode;

extern const float WHEEL_MAX_OCCUPANCY;
extern float WHEEL_MAX_VERTICAL_OCCUPANCY;

extern float NOTE_RADIUS_SCALE;
extern float NOTE_GLOW_SCALE;
extern float NOTE_POLYGON_THICKNESS;
extern float NOTE_POLYGON_GLOW_THICKNESS;

extern float CIRCLE_DEFAULT_RADIUS;

#define UI_MIN_WIDTH 400
#define UI_MIN_HEIGHT 70
#define UI_MARGIN 8

#define SIDE_BUTTON_WIDTH 0.15
#define SIDE_BUTTON_HEIGHT SIDE_BUTTON_WIDTH * 0.53

#endif // LAYOUT_H
