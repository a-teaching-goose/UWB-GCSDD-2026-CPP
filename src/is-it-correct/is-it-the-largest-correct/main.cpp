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
    int array1[] = {9, 3, 4, 1};
    checkLargest(array1, 4, 9);

    int array2[] = {9, 8, -1, 7, 2, 2};
    checkLargest(array2, 6, 9);

    int array3[] = {9, 8, 10, 2, 2};
    checkLargest(array3, 5, 10);

    // what other tests can we add to make us more confident this code is correct?

    return 0;
}
