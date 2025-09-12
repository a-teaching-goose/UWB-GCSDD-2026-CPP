#include <iostream>

// The function is implemented in another source file for this Is It Correct activity.
// Do not open that file until after writing more tests.
bool isPassing(int score);

void checkIsPassing(int score, bool expected) {
    bool actual = isPassing(score);

    // Passing tests are silent. Failures show enough information to debug.
    if (actual != expected) {
        std::cerr << "FAIL: isPassing(" << score << ")\n"
                  << "  expected: " << std::boolalpha << expected << "\n"
                  << "  actual:   " << actual << "\n";
    }
}

int main() {
    // One starting test.
    checkIsPassing(82, true);

    // TODO: Add tests for 60, 59, 0, and 100.
    return 0;
}
