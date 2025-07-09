CXX=g++
CXXFLAGS=-std=c++17 -Iinclude
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)
TARGET=segment_tree

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

