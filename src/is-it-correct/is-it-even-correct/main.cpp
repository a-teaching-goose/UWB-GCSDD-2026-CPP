#include <iostream>

// The function is implemented in another source file for this Is It Correct activity.
// Do not open that file until after writing more tests.
bool isPassing(int score);


// unit test
void checkIsPassing(int grade, bool expected) {
    bool actual = isPassing(grade);

    // Passing tests are silent. Failures show enough information to debug.
    if (actual != expected) {
        std::cerr << "FAIL: isPassing(" << grade << ")\n"
                  << "  expected: " << std::boolalpha << expected << "\n"
                  << "  actual:   " << actual << "\n";
    }
}

int main() {
    checkIsPassing(82, true);

    return 0;
}
