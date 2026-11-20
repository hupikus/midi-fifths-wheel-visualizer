#include <stdbool.h>
#include <stddef.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <raylib.h>

#include "ui/midi_select.h"


typedef struct {
	const char *name;
	unsigned int port;
} midiDevice;

typedef struct midiListItem {
    midiDevice item;
    bool enabled;
    struct midiListItem *next;
} midiListItem;

midiListItem midiList = {0};

void UI_SetMidiDevice(const char *dev_name, unsigned int dev_port)
{
    midiListItem *dev = &midiList;

    while (1) {
        if (dev->item.port == dev_port) {
            if (strcmp(dev->item.name, dev_name) == 0) {
                dev->enabled = true;
                return;
            } else {
                dev->enabled = false;
            }
        }

        if (dev->next != NULL) {
            dev = dev->next;
        } else { break; }

    }

    assert(dev != NULL);

    midiListItem *new_dev = malloc(sizeof(midiListItem));
    new_dev->item = (midiDevice){dev_name, dev_port};
    new_dev->next = NULL;
    new_dev->enabled = true;

    dev->next = new_dev;
}

// Remove all disabled devices from UI
void UI_OptimizeMidiList()
{
    midiListItem *dev = &midiList;

    while (dev->next != NULL) {
        midiListItem *next = dev->next;
        if (!next->enabled) {
            dev->next = next->next;
            free(next);
        } else {
            dev = next;
        }
    }
}

void UI_ClearMidiList()
{
    midiListItem *dev = midiList.next;

    while (dev != NULL) {
        midiListItem *next = dev->next;
        free(dev);
        dev = next;
    }

    midiList = (midiListItem){0};
}
