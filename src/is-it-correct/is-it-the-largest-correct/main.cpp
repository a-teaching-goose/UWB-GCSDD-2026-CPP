#include <iostream>

// The function is implemented in another source file for this Is It Correct activity.
// Do not open that file until after adding more tests.
int findLargest(const int values[], int size);

void checkLargest(const int values[], int size, int expected) {
    int actual = findLargest(values, size);

    // Passing tests are silent. Failures show enough information to debug.
    if (actual != expected) {
        std::cerr << "FAIL: findLargest(values, " << size << ")\n"
                  << "  expected: " << expected << "\n"
                  << "  actual:   " << actual << "\n";
    }
}

int main() {
    // This test passes because the largest value happens to be first.
    int firstIsLargest[] = {9, 3, 4, 1};
    checkLargest(firstIsLargest, 4, 9);

    return 0;
}
