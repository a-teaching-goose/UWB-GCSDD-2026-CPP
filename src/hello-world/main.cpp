#include <iostream>

int main() {
    int a = 10;
    std::string s = "Hello World!";

    // control flows
    for (int i =0; i<a; i++) {
        if (!(i%2)) {
            std::cout << i << ": " << s << "\n" << std::endl;
        }
    }
}
