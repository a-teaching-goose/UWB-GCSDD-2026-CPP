#include <iostream>

// Dangling-pointer demo: this function returns the address of a local array.
// The entire array disappears when the function returns.
int* makeDanglingArray() {
    int localNumbers[5] = {1, 2, 3, 4, 5};
    return localNumbers;  // Intentional bug: returning an address on the stack.
}

int main() {
    int* danglingArray = makeDanglingArray();

    // This is undefined behavior. The array no longer exists.
    // Writing through this pointer can overwrite unrelated stack memory.
    for (int i = 0; i < 5; ++i) {
        danglingArray[i] = (i + 1) * 10;
    }

    std::cout << "First value: " << danglingArray[0] << "\n";
    return 0;
}
