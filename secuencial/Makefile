# Makefile para la versión secuencial

CC = g++
CFLAGS = -std=c++11 -Wall
LIBS = `pkg-config --cflags --libs opencv4`

all:	secuencial

secuencial:	sec.cpp
	$(CC) $(CFLAGS) -o secuencial sec.cpp $(LIBS)

clean:
	rm -f secuencial

