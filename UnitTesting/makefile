CC=g++
CFLAGS= -std=c++11 -w
INCLUDES = -Icppunit-1.13.2/include/ -Icppunit-1.13.2/include/cppunit
LIBS = -Lcppunit-1.13.2/lib -Lcppunit-1.13.2/src/ -Lcppunit-1.13.2/examples/cppunittest/ -Lcppunit-1.13.2/src/cppunit/
SOURCES=UnitTest.cpp 
EXECUTABLE=UnitTest
LDFLAGS = -lcppunit -ldl
LIB_SO = cppunit-1.13.2/src/

all:
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(EXECUTABLE) $(SOURCES) $(LDFLAGS)