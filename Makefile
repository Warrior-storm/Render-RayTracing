CC = gcc
CFLAGS = -Wall -Wextra -I./src

SOURCES = main.c src/Vector.c src/Esfera.c src/Camara.c src/Escena.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = programa

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean