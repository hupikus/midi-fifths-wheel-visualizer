#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include <rtmidi/rtmidi_c.h>
#include "midi/midi.h"

#include "options.h"
#include "keys.h"

#include "widgets/midi_select.h"

RtMidiInPtr midi_in = NULL;
unsigned int port = 0;

bool running = true;
bool connected = false;
bool midi_error = false;

#define MIDI_OFF 0
#define MIDI_ON 64

#define MIDI_NOTE_OFF 0x80
#define MIDI_NOTE_ON 0x90


#include <stdio.h>
void MidiCallback(double timestamp,
                   const unsigned char *msg,
                   size_t msg_size,
                   void *user_data)
{
    unsigned char status = msg[0] & 0xF0;
    unsigned char channel = msg[0] & 0x0F;

    if (msg_size < 3) return;

    if (status == MIDI_NOTE_ON)
    {
        assert(msg[2] > 0);
        PressKey(msg[1]);
        //printf("Note pressed\n");
    } else if (status == MIDI_NOTE_OFF) {
        assert(msg[2] == 0);
        ReleaseKey(msg[1]);
        //printf("Note released\n");
    }
}


void disconnect()
{
    rtmidi_in_cancel_callback(midi_in);
    rtmidi_close_port(midi_in);
    connected = false;
}

void *InitMidi(void *arg)
{
    midi_in = rtmidi_in_create_default();

    if (!midi_in)
    {
        midi_error = true;
        return NULL;
    }

    while (running) {
        unsigned int count = rtmidi_get_port_count(midi_in);
        if (!connected || port < MIDI_SELECTION) {
            if (connected) { disconnect(); }

            for (unsigned int i = 0; i < count; ++i)
            {
                int buflen = 256;
                char buffer[buflen];

                enum RtMidiErrorType error;
                rtmidi_get_port_name(midi_in, i, &buffer[0], &buflen);
                if (!buffer[0]) continue;

                //UI_SetMidiDevice(&buffer[0], i);
                if (i < MIDI_SELECTION) {
                    continue;
                }

                rtmidi_open_port(midi_in, i, "Keyboard");
                port = i;
                printf("Connecting to keyboard %s on port %u\n", &buffer[0], port);
                connected = true;

                rtmidi_in_set_callback(midi_in, MidiCallback, NULL);
            }
        }
        if (connected && port >= count)
        {
            disconnect();
        }

        usleep(RECONNECT_TIME * 1000);
    }

    rtmidi_in_free(midi_in);
}

void TerminateMidi()
{
    running = false;
}
