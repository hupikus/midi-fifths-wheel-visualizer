#ifndef OPTIONS_H
#define OPTIONS_H
#include <stdbool.h>

#define WIDTH 1200
#define HEIGHT 720

#define MODE_WHEEL 0
#define MODE_KEYBOARD 1
#define MODE_TRANSITION -1

extern int mode;

extern const float MAX_OCCUPANCY;
extern float MAX_VERTICAL_OCCUPANCY;

extern float NOTE_RADIUS_SCALE;
extern float NOTE_GLOW_SCALE;
extern float NOTE_POLYGON_THICKNESS;
extern float NOTE_POLYGON_GLOW_THICKNESS;

extern float CIRCLE_DEFAULT_RADIUS;


extern float RECONNECT_TIME;

#endif // OPTIONS_H
