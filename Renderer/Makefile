CC=g++
CFLAGS= -std=c++11 -w
INCLUDES = -Iinclude/ -Ilibs/i686-w64-mingw32/include/ -Ilibs/SOIL/src
LIBS = -Llibs/SOIL/lib 
SOURCES=src/main.cpp 
LDFLAGS = -lSOIL 
LIB_SO = 

ifeq ($(OS),Windows_NT)
	EXECUTABLE=Main.exe
	LIBS += -Llibs/i686-w64-mingw32/lib -Llibs/SOIL/lib
	LDFLAGS += -lmingw32 -lopengl32 -lglu32
	OBJECTS=obj/Win32/glew.o

	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		LIBS += -L"libs/irrKlang/irrKlang-32bit-1.5.0/lib/Win32-gcc/"
		INCLUDES += -I"libs/irrKlang/irrKlang-64bit-1.5.0/include/"
	endif

	LIBS += -L"libs/irrKlang/irrKlang-32bit-1.5.0/lib/Win32-gcc/"
	INCLUDES += -I"libs/irrKlang/irrKlang-32bit-1.5.0/include/"
else
	EXECUTABLE=Main
	LDFLAGS += -lGL -lGLU -lglut
	OBJECTS=obj/Unix/x64/glew.o 

	LBITS := $(shell getconf LONG_BIT)
	ifeq ($(LBITS),64)
		OBJECTS=obj/Unix/x64/glew.o 
		LIB_SO += libs/irrKlang/irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so
		INCLUDES += -I"libs/irrKlang/irrKlang-64bit-1.5.0/include/"
	else
		OBJECTS=obj/Unix/x86/glew.o 
		LIBS += libs/irrKlang/irrKlang-64bit-1.5.0/bin/linux-gcc/libIrrKlang.so
		INCLUDES += -I"libs/irrKlang/irrKlang-32bit-1.5.0/include/"
	endif
	
	LDFLAGS += -pthread
endif

LDFLAGS += -lSDL2main -lSDL2 

all:
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(EXECUTABLE) $(SOURCES) $(OBJECTS) $(LIB_SO) $(LDFLAGS)