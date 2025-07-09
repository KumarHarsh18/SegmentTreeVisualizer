CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

INCLUDE_DIR = include
SRC_DIR = src

SRCS = $(SRC_DIR)/SegmentTree.cpp $(SRC_DIR)/main.cpp
OBJS = $(SRCS:.cpp=.o)

EXEC = visualizer

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(EXEC)
