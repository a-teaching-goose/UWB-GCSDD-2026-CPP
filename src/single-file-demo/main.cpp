#include <cstddef>
#include <iostream>

constexpr std::size_t bytesPerCall = 1024 * 1024;  // 1 MB per call.

void measureStack(int callNumber) {
    char localArray[bytesPerCall] = {};
    localArray[0] = 'x';

    // std::endl flushes the output so we see this line before a crash.
    std::cout << "Recursive call: " << callNumber << std::endl;

    measureStack(callNumber + 1);
}

int main() {
    std::cout << "sizeof(char): " << sizeof(char) << " byte\n";
    std::cout << "array memory per call: " << bytesPerCall << " bytes\n";

    measureStack(1);
}