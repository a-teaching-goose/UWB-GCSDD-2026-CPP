# Build the dangling-pointer memory demo.
# Run `make`, then run `./dangling_pointer` at your own risk.

CXX := g++
CXXFLAGS := -std=c++17 -O0 -g -Wall -Wextra
BIN := dangling_pointer

all:
	$(CXX) $(CXXFLAGS) dangling_pointer.cpp -o $(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean
