#include <iostream>

bool isPass(int);

int main() {
    for (int grade = 0; grade<=100; grade++) {
        std::cout << grade << (isPass(grade) ? ": Pass" : ": Fail") << std::endl;
    }
}

bool isPass(int grade) {
    return grade>=60;
}
