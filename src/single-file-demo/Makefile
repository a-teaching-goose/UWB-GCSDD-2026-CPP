# A Makefile gives names to the commands used to build this program.
# Run `make` to compile it, then run `./mariolab`.

# The C++ compiler. On macOS this is usually Clang; on Ubuntu it is usually GCC.
CXX := g++

# Use C++17 and ask the compiler to warn about common mistakes.
CXXFLAGS := -std=c++17 -Wall -Wextra

# The program that this demo creates.
BIN := mariolab

# The default target: compile main.cpp into the executable.
all:
	$(CXX) $(CXXFLAGS) main.cpp -o $(BIN)

# Remove the executable so the demo can be built from scratch.
clean:
	rm -f $(BIN)
