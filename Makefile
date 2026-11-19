CC ?= gcc

NAME=viz

SRC=main.c
LDFLAGS=-lraylib


OBJ=$(SRC:.cpp=.o)

.PHONY: main

%.o: %.c
	$(CC) -c $< -o $@

main: $(OBJ)
	$(CC) $(LDFLAGS) $< -o $(NAME)

clean:
	rm -f **.o
	rm -f ./$(NAME)

run: main
	./$(NAME)
