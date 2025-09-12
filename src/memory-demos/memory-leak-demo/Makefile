# Build the DynamicArray memory-leak demo.
# Run `make`, then run `./memory_leak`.

CXX := g++
CXXFLAGS := -std=c++17 -O0 -g -Wall -Wextra
BIN := memory_leak

all:
	$(CXX) $(CXXFLAGS) memory_leak.cpp -o $(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean
