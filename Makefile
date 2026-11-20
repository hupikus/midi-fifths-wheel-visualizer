CC ?= gcc

NAME=viz

SRC=main.c \
    midi/midi.c \
    display/shaders.c \
    options.c colors.c keys.c \
    display/widgets/midi_select.c \
    display/circle.c display/notes.c display/note_polygon.c \
    display/note_text.c display/fonts.c \

FLAGS=-Idisplay/ -I./
LDFLAGS=-lm -lraylib -lrtmidi


OBJ=$(SRC:.c=.o)

.PHONY: main run clean shaders

main: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

display/shaders.o: shaders.htmp

clean:
	rm -f **.o
	rm -f *.htmp


$(NAME): main

run: $(NAME)
	./$(NAME)


SHADERS = radial_glow line_gradient

SHADER_FILES = $(addprefix shaders/,$(addsuffix .glsl,$(SHADERS)))

shaders.htmp: $(SHADER_FILES)
	@rm -f shaders.htmp
	@for shader in $(SHADERS); do \
		printf 'const char *%s_shader =\n' "$$shader" >> shaders.htmp; \
		sed -e 's/\\/\\\\/g' -e 's/"/\\"/g' -e 's/$$/\\n/' \
			shaders/$$shader.glsl | \
			sed 's/^/"/; s/\\n$$/\\n"/' >> shaders.htmp; \
		printf ';\n' >> shaders.htmp; \
	done
