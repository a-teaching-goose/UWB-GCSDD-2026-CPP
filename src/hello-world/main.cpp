#include <iostream>

int main() {
    int * ptr = new int[10];    // allocate 10 int vars from heap

    for (int i = 0; i < 10; i++) {
        ptr[i] = i+1;
    }

    *(ptr+4) = 99;

    for (int i = 0; i < 10; i++) {
        std::cout << ptr[i] << std::endl;
    }
}
