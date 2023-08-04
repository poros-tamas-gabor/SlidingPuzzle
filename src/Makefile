# Makefile for 8 pieces sliding puzzle C++ program 

# Compiler and flags 
CXX := g++
CXXFLAGS = -std=c++11 -Wall -O2 
# Usage
# make - compile the source code and create the executable file
# make clean - delete the object files

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
	rm -rvf *.o $(OBJS) $(TARGET)

