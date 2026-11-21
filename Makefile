CC ?= gcc

NAME=viz

SRC=main.c \
    midi/midi.c \
    display/fonts.c display/shaders.c \
    options.c colors.c keys.c \
    display/widgets/widgets.c


WIDGET_WHEEL = \
    widget.c circle.c notes.c note_polygon.c \
    note_text.c
WIDGET_WHEEL := $(addprefix display/widgets/wheel/,$(WIDGET_WHEEL))

WIDGET_MIDI_SELECT = widget.c midi_list.c
WIDGET_MIDI_SELECT := $(addprefix display/widgets/midi_select/,$(WIDGET_MIDI_SELECT))


SRC += $(WIDGET_WHEEL)
SRC += $(WIDGET_MIDI_SELECT)

FLAGS=-Idisplay/ -I./
LDFLAGS=-lm -lraylib -lrtmidi


OBJ=$(SRC:.c=.o)

.PHONY: main run clean shaders

main: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@


SHADERS_FILE=shaders/shaders.htmp
display/shaders.o: $(SHADERS_FILE)

clean:
	rm -f $(OBJ)
	rm -f shaders/*.htmp


$(NAME): main

run: $(NAME)
	./$(NAME)


SHADERS = radial_glow line_gradient

SHADER_FILES = $(addprefix shaders/,$(addsuffix .glsl,$(SHADERS)))

$(SHADERS_FILE): $(SHADER_FILES)
	@rm -f $(SHADERS_FILE)
	@for shader in $(SHADERS); do \
		printf 'const char *%s_shader =\n' "$$shader" >> $(SHADERS_FILE); \
		sed -e 's/\\/\\\\/g' -e 's/"/\\"/g' -e 's/$$/\\n/' \
			shaders/$$shader.glsl | \
			sed 's/^/"/; s/\\n$$/\\n"/' >> $(SHADERS_FILE); \
		printf ';\n' >> $(SHADERS_FILE); \
	done
