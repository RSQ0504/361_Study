CC = g++ -std=c++17
CFLAGS = -g -Wall

OPENCV = `pkg-config opencv4 --cflags --libs`
LIBS = $(OPENCV)

main: main.cpp Color.h Color.cpp
		$(CC) $(CFLAGS) -o main main.cpp Color.cpp $(LIBS)
