C = g++
CFLAGS = -std=c++11 -Wall -pthread
LIBS = `pkg-config --cflags --libs opencv4`

TARGET = thread
SOURCE = thread.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(C) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LIBS)

clean:
	rm -f $(TARGET)
