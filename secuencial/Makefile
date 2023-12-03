# Makefile para la versión secuencial

CC = g++
CFLAGS = -std=c++11 -Wall
LIBS = `pkg-config --cflags --libs opencv4`

TARGET = secuencial
SOURCE = sec.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
        $(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE) $(LIBS)

clean:
        rm -f $(TARGET)
