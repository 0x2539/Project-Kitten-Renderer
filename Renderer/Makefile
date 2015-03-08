CC=g++
CFLAGS= -Wall -Iinclude/ 
LDFLAGS= -lSDL2 -lSDL2main -lGL -lGLU -lglut
SOURCES=src/main.cpp 
OBJECTS=obj/glew.o

ifeq ($(OS),Windows_NT)
	EXECUTABLE=Main.exe
else
	EXECUTABLE=Main
endif

all:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECUTABLE) $(SOURCES) $(OBJECTS)