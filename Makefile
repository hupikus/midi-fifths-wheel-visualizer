CC ?= gcc

NAME=viz

SRC=main.c \
    display/shaders.c \
    display/circle.c display/notes.c \
    display/note_text.c display/fonts.c \
    options.c colors.c \
    keys.c

FLAGS=-Idisplay/ -I./
LDFLAGS=-lm -lraylib


OBJ=$(SRC:.c=.o)

.PHONY: main run clean shaders

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

main: shaders $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f **.o
	rm -f *.htmp


$(NAME): main

run: $(NAME)
	./$(NAME)


SHADERS = radial_glow
shaders: $(addprefix shaders/,$(addsuffix .glsl,$(SHADERS)))
	@rm -f shaders.htmp
	@for shader in $(SHADERS); do \
		printf 'const char *%s_shader =\n' "$$shader" >> shaders.htmp; \
		sed -e 's/\\/\\\\/g' -e 's/"/\\"/g' -e 's/$$/\\n/' \
			shaders/$$shader.glsl | \
			sed 's/^/"/; s/\\n$$/\\n"/' >> shaders.htmp; \
		printf ';\n' >> shaders.htmp; \
	done
