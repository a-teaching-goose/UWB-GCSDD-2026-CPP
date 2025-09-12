# Build the Is It Correct unit-testing demo from its two source files.

CXX := g++
CXXFLAGS := -std=c++17 -O0 -g -Wall -Wextra
BIN := is_it_even_correct

all:
	$(CXX) $(CXXFLAGS) main.cpp is_passing.cpp -o $(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean
