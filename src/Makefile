# Makefile for C++ program 

# Compiler and flags 
CXX := g++
CXXFLAGS = -std=c++11 -Wall -O2 

TARGET := sliding_puzzle
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all : $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp
	@echo "Creating objs"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -rvf *.o $(BINS)

