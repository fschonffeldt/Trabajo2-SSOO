C = g++
CFLAGS = -std=c++11 -Wall -fopenmp
LIBS = `pkg-config --cflags --libs opencv4`

TARGET = openmp
SOURCE = openMP.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(C) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LIBS)

clean:
	rm -f $(TARGET)
