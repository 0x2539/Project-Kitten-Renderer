CC=g++
CFLAGS= -Wall -Iinclude/ -Ilibs/i686-w64-mingw32/include/
LDFLAGS= -lmingw32 -lopengl32 -lglu32 -lSDL2main -lSDL2
SOURCES=src/main.cpp 
OBJECTS=obj/glew.o

ifeq ($(OS),Windows_NT)
	EXECUTABLE=Main.exe
	CC += -Llibs/i686-w64-mingw32/lib
else
	EXECUTABLE=Main
endif

all:
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) $(OBJECTS) $(LDFLAGS)

#$(LIBS)