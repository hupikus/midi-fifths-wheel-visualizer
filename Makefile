CC ?= g++

NAME=viz

SRC=main.cpp
LDFLAGS=-lraylib


OBJ=$(SRC:.cpp=.o)

.PHONY: main

%.o: %.cpp
	$(CC) -c $< -o $@

main: $(OBJ)
	$(CC) $(LDFLAGS) $< -o $(NAME)

clean:
	rm -f **.o
	rm -f ./$(NAME)

run: main
	./$(NAME)
