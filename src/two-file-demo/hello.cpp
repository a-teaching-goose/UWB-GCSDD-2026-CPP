#include <iostream>

#include "hello.h"

void printHello(int numberOfTimes) {
    for (int i = 0; i < numberOfTimes; ++i) {
        std::cout << "Hello, World!" << std::endl;
    }
}
