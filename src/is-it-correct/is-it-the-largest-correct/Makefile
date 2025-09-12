# Build the Is It Correct largest-value unit-testing demo.

CXX := g++
CXXFLAGS := -std=c++17 -O0 -g -Wall -Wextra
BIN := is_it_the_largest_correct

all:
	$(CXX) $(CXXFLAGS) main.cpp find_largest.cpp -o $(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean
