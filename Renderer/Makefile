CC=g++
CFLAGS= -Wall -std=c++11 -Iinclude/ -Ilibs/i686-w64-mingw32/include/
SOURCES=src/main.cpp 

ifeq ($(OS),Windows_NT)
	EXECUTABLE=Main.exe
	CC += -Llibs/i686-w64-mingw32/lib
	LDFLAGS = -lmingw32 -lopengl32 -lglu32
	OBJECTS=obj/Win32/glew.o
else
	EXECUTABLE=Main
	LDFLAGS = -lGL -lGLU -lglut
	OBJECTS=obj/Unix/glew.o
endif

LDFLAGS += -lSDL2main -lSDL2

all:
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) $(OBJECTS) $(LDFLAGS)

#$(LIBS)
