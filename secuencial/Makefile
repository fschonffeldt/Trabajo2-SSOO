# Makefile para la versión secuencial

CXX = g++
CXXFLAGS = -std=c++11 -Wall
LIBS = 'pkg-config --cflags --libs opencv4'

TARGET = secuencial
SOURCE = main_secuencial.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE) $(LIBS)

clean:
	rm -f $(TARGET)
