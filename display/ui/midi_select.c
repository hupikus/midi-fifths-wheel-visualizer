#include <stdbool.h>
#include <stddef.h>
#include <memory.h>
#include <string.h>
#include <assert.h>

#include <raylib.h>

#include "ui/midi_select.h"


typedef struct {
	const char *name;
	unsigned int port;
} midiDevice;

typedef struct {
    midiDevice item;
    bool enabled;
    midiListItem *next;
} midiListItem;

midiListItem midiList = {0};

void UI_SetMidiDevice(const char *dev_name, unsigned int dev_port)
{
    midiListItem *dev = &midiList;

    while (1) {
        if (dev->item->port == dev_port) {
            if (strcmp(dev->item->name, dev_name) == 0) {
                if (!dev->item-enabled) {
                    dev->item->enabled = true;
                    return;
                }
            } else {
                dev->item->enabled = false;
            }
        }

        if (dev->next != NULL) {
            dev = dev->next;
        } else { break; }

    }

    assert(dev != NULL);

    midiListItem *new_dev = malloc(sizeof midiListItem);
    new_dev->item = (midiDevice){dev_name, dev_port};
    new_dev->next = NULL;
    new_dev->enabled = true;

    dev->next = new_dev;
}

void UI_OptimizeMidiList()
{
}

void UI_ClearMidiList()
{
}
