<img width="100%" alt="Cartoon C++ workshop with a vintage computer and machinery behind a curtain" src="assets/cpp-bootup-cartoon-cover.png" />

# 2026 UWB C++ GCSDD BootUp Notes

This is a practical C++ starter guide for CSS 342c. During class, we will write small programs together. Every example below is complete, so you can copy it into a `.cpp` file, compile it, and experiment with it.

---

## Session recording

The recording link will be posted here after the session.

## Linux session

Students using Linux can find the Linux session materials in [GCSDD BootUp 2026-09-17 Linux](https://github.com/a-teaching-goose/GCSDD_BootUp_2026-09-17_Linux).

## Got a question?

Contact pengdu@uw.edu

---

## Build your first C++ program

Start with the complete one-file example in [`src/single-file-demo/`](src/single-file-demo/). Its [`main.cpp`](src/single-file-demo/main.cpp) prints a short message, so you can focus on the build process first.

Open a terminal in that folder:

```bash
cd src/single-file-demo
```

### Compile with the compiler

This command compiles `main.cpp` and creates an executable named `mariolab`:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o mariolab
./mariolab
```

- `g++` starts the C++ compiler. On macOS, it commonly invokes Apple Clang; on Ubuntu, it commonly invokes GCC.
- `-std=c++17` selects the C++17 language standard.
- `-Wall -Wextra` ask the compiler to report common mistakes.
- `-o mariolab` names the executable that is created.

### Compile with Make

The [Makefile](src/single-file-demo/Makefile) stores the compiler command so that you do not need to type it every time:

```bash
make
./mariolab
```

Use `make clean` to remove the generated executable.

### Compile with CMake

The [CMakeLists.txt](src/single-file-demo/CMakeLists.txt) describes the same program in a portable way. CMake puts its generated files in a separate `build` folder:

```bash
mkdir build
cd build
cmake ..
cmake --build .
./mariolab
```

**Practice:** Change the message in `main.cpp`, then rebuild it with the direct compiler command, Make, and CMake. What does each approach save you from typing?

---

## 1. Variables and output

Variables store values. In C++, every variable has a type. Common types include `int` for whole numbers, `double` for decimal numbers, `char` for one character, and `std::string` for text.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name = "Ada";
    int year = 2026;
    double courseNumber = 342.0;

    std::cout << name << " is taking CSS " << courseNumber
              << " in " << year << ".\n";
    return 0;
}
```

**Practice:** Create variables for your name, your favorite number, and your favorite programming language. Print one sentence that uses all three.

## 2. Decisions and loops

Use `if` / `else` when the program must choose between actions. Use a `for` loop when work needs to repeat.

```cpp
#include <iostream>

int main() {
    int score = 82;

    if (score >= 60) {
        std::cout << "Passing\n";
    } else {
        std::cout << "Keep practicing\n";
    }

    std::cout << "Counting: ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
```

**Practice:** Write a loop that prints the even numbers from 2 through 20. Then change the `if` statement so that a score of 90 or above prints `Excellent`.

## 3. Functions

A function gives a name to a task. Here, we move the pass/fail decision from the previous section into a function. The parameter is the score, and the returned `bool` tells `main` which message to print.

```cpp
#include <iostream>

bool isPassing(int score) {
    return score < 60;
}

int main() {
    int score = 82;

    if (isPassing(score)) {
        std::cout << "Passing\n";
    } else {
        std::cout << "Keep practicing\n";
    }

    return 0;
}
```

Keeping the decision in `isPassing` makes `main` easier to read. It also gives us one place to test the rule.

**Practice:** Add a second function named `isExcellent` that returns `true` for scores of 90 or above. Call it from `main` to print `Excellent` when appropriate.

## 4. Is it right? Own your code.

Who is responsible for making our code correct: the teacher, the professor, or someone reviewing a pull request? They can help us learn and catch mistakes, but the answer is **we own our code**. We are responsible for understanding what it should do and for giving ourselves evidence that it does it.

Testing gives us that evidence in two important ways:

1. **Correctness:** a unit test checks that one small piece of code gives the result we intended for a known input.
2. **Regression protection:** when a teammate improves or reorganizes code later, tests help ensure that the original behavior was not accidentally changed.

A **unit test** calls one small unit of code with known inputs and compares the actual result with the expected result. We can write simple tests without an external framework.

### Example 1: Is it even correct?

Use [`src/is-it-correct/is-it-even-correct/`](src/is-it-correct/is-it-even-correct/). Begin by opening only [`main.cpp`](src/is-it-correct/is-it-even-correct/main.cpp). It contains one test and TODOs for students to add more; keep [`is_passing.cpp`](src/is-it-correct/is-it-even-correct/is_passing.cpp) closed at first.

The test helper follows a convention used by many test frameworks: successful checks are silent, and a failure shows the input, expected value, and actual value.

```cpp
bool isPassing(int score);  // Implemented in another file.

void checkIsPassing(int score, bool expected) {
    bool actual = isPassing(score);

    if (actual != expected) {
        std::cerr << "FAIL: isPassing(" << score << ")\n"
                  << "  expected: " << std::boolalpha << expected << "\n"
                  << "  actual:   " << actual << "\n";
    }
}

int main() {
    checkIsPassing(82, true);
    // Add tests for 60, 59, 0, 100, and -1.
}
```

This activity shows how to write a test and how a failing result leads us back to the logic that needs fixing. Once the correct behavior is established, these tests also become regression tests: later changes must keep the same pass/fail rule.

### Example 2: Is the largest-number test correct?

Next, use [`src/is-it-correct/is-it-the-largest-correct/`](src/is-it-correct/is-it-the-largest-correct/). Its starter test passes silently because the first number in its array is already the largest. A passing test is encouraging, but it does **not** prove that the implementation is correct.

Add tests where the largest value is in the middle and at the end, such as `{3, 9, 4, 1}` and `{3, 4, 1, 9}`. These tests expose the defect. After that, reveal the hidden implementation. The actual source has no giveaway comments; this annotated version explains the problem:

```cpp
int findLargest(const int values[], int size) {
    int largest = values[0];

    for (int i = 0; i < size; ++i) {
        if (values[i] > largest) {
            // Bug: this should be values[i].
            // Assigning values[0] makes the function keep the first value.
            largest = values[0];
        }
    }

    return largest;
}
```

This is the key lesson: do not trust a test just because it passes. Test cases must cover different situations, especially boundary cases and positions that exercise different paths through the code.

### How do we know that a test is correct?

This question leads to **test-driven development (TDD)**. The basic cycle is:

1. Write a test that expresses the behavior you want.
2. Run it before adding the behavior; it should fail.
3. Add or change the smallest amount of code needed to make the test pass.
4. Keep the test as regression protection while you improve the code.

If a new test passes even before the behavior or fix has been added, stop and inspect the test. It may not be testing the case you thought it was. TDD does not make testing perfect, but it gives us a disciplined way to check both our code and our tests.

**Practice:** For each activity, write at least one test that fails before the fix and passes after it. Explain which behavior that test protects from future regressions.

## 5. Memory, pointers, references, and leaks

Local variables such as `int score = 82;` are usually stored on the **stack** and are cleaned up automatically when their scope ends. Dynamically allocated memory lives on the **heap** and must be released by the programmer.

### Pointers

A pointer stores a memory address. The `&` operator gets an address, and `*` follows a pointer to access the value at that address.

```cpp
#include <iostream>

int main() {
    int score = 82;
    int* scorePointer = &score;

    std::cout << "Before: " << score << "\n";
    *scorePointer = 100;
    std::cout << "After: " << score << "\n";

    return 0;
}
```

**Practice:** Create an `int` named `temperature`, make a pointer to it, and use the pointer to increase the temperature by 5.

### References

A reference is another name for an existing variable. References are useful when a function should change the caller's variable without using pointer syntax at the call site.

```cpp
#include <iostream>

void addOne(int& number) {
    number += 1;
}

int main() {
    int lives = 2;
    addOne(lives);
    std::cout << "Lives: " << lives << "\n";
    return 0;
}
```

**Practice:** Write a function `swapNumbers` that takes two `int` references and swaps their values.

### Dynamic memory and a memory leak

`new` allocates memory on the heap. For every `new[]`, the program must eventually use `delete[]` on the same pointer. Forgetting that cleanup creates a **memory leak**: the program may appear to run correctly, but it leaves memory allocated.

```cpp
#include <iostream>

int main() {
    int* numbers = new int[3]{10, 20, 30};

    std::cout << "First number: " << numbers[0] << "\n";

    delete[] numbers;  // Give the heap memory back when we are finished.
    return 0;
}
```

For the debugging demo, remove the `delete[] numbers;` line. The program will often still print the expected answer, especially on macOS, but a Linux memory-checking tool can report the leak. Add the line back to fix it.

**Practice:** Change the array to hold five values. Print all five with a loop, and make sure the program still calls `delete[]` exactly once.

### Live debugging demos

The complete programs are kept in [`src/memory-demos/`](src/memory-demos/) so that you can build and inspect them separately.

#### Dangling pointer

[`dangling_pointer.cpp`](src/memory-demos/dangling-pointer-demo/dangling_pointer.cpp) creates an array inside a function and returns its address. That array was stored in the function's stack frame, so it no longer exists when the function returns. The caller then tries to write values through the returned pointer.

```cpp
int* makeDanglingArray() {
    int localNumbers[5] = {1, 2, 3, 4, 5};
    return localNumbers;  // Invalid after this function returns.
}
```

Writing through that pointer is **undefined behavior**. The program might seem to work, print garbage, corrupt other stack data, or crash. The compiler warning is an early clue that the returned address is unsafe.

#### Memory leak

[`memory_leak.cpp`](src/memory-demos/memory-leak-demo/memory_leak.cpp) implements a resizing `DynamicArray` that owns an `int*` array. When it grows, it correctly deletes the old array. However, the class intentionally has no destructor, so its final allocated array is never released when the object goes out of scope.

```cpp
// Missing from the starter code:
~DynamicArray() {
    delete[] data_;
}
```

The program prints the correct squares on macOS, but Valgrind on Linux reports the leaked allocation. Add the destructor above, rerun the check, and confirm that the leak is gone.

### Check both programs with Valgrind on Linux

Valgrind runs the program while checking how it uses memory. On Ubuntu, install it once if it is not already available:

```bash
sudo apt install valgrind
```

Build and check the dangling-pointer demo:

```bash
cd src/memory-demos/dangling-pointer-demo
make
valgrind --track-origins=yes --error-exitcode=1 ./dangling_pointer
```

Valgrind should report an **Invalid write** or **Invalid read** when the caller uses the address of the vanished local array. That report points to the bug: do not return a pointer to local stack storage. Instead, let the caller own the array or return an object that safely owns its data.

Build and check the memory-leak demo:

```bash
cd src/memory-demos/memory-leak-demo
make
valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./memory_leak
```

The output should include a **definitely lost** allocation. The allocation trace leads back to `DynamicArray`, telling us that the class allocates memory but does not release its final `data_` array. Add the destructor, rebuild, and rerun Valgrind. A successful fix reports no definitely lost blocks and exits with status `0`.

### Stack growth with recursion

Every function call needs its own stack frame. This experiment puts a 1 MB `char` array in each call, then simply calls itself again. After only a few calls, the program should reach its stack limit and stop with a stack-overflow crash.

> **Run this only as a local experiment.** It is supposed to crash. Save your work first, compile without optimization, and stop the program with `Ctrl+C` if you do not want to wait for the crash.

```cpp
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
```

Compile this example without optimization so that the compiler does not transform the experiment:

```bash
g++ -std=c++17 -O0 -Wall -Wextra stack_size.cpp -o stack_size
./stack_size
```

In C++, `sizeof(char)` is always 1 byte, so the array uses exactly 1,048,576 bytes (1 MiB) per recursive call on every platform. The true stack use is slightly larger because each function call also has bookkeeping information and alignment padding. The exact stack limit varies by operating system, compiler, and configuration.

### Check the Linux stack limit

On Linux, run this command in the same terminal before starting the program:

```bash
ulimit -s
```

The result is the stack-size limit in KiB. A common result is `8192`, which means 8,192 KiB, or 8 MiB. With a 1 MiB array in every call, the program may print about seven calls before it overflows. The stack is not available entirely to our array: `main`, function-call bookkeeping, output code, and a guard area use some of the 8 MiB too.

**Practice:** Compare the final call number with the `ulimit -s` result. Then change `bytesPerCall` to 512 KB, then to 2 MB. How does the number of successful recursive calls change before the stack overflows?

## 6. Classes and objects

A class describes a new kind of thing. An object is one value created from that class. This example has a class with data (`name` and `year`) and one behavior (`introduce`).

```cpp
#include <iostream>
#include <string>

class Student {
public:
    Student(const std::string& studentName, int studentYear)
        : name(studentName), year(studentYear) {}

    void introduce() const {
        std::cout << "I am " << name << " in year " << year << ".\n";
    }

private:
    std::string name;
    int year;
};

int main() {
    Student firstStudent("Ada", 1);
    Student secondStudent("Grace", 2);

    firstStudent.introduce();
    secondStudent.introduce();
    return 0;
}
```

**Practice:** Add a `major` field to `Student`. Update the constructor and `introduce` so that each student prints their major too.

## 7. Moving work between machines

Git lets you continue the same work on a different machine. In the memory-leak demo, we will run the program on macOS, move the code to Linux, identify the leak with a program check, make the fix, and bring the change back.

The important idea is that a program can appear to work while still containing a serious memory-management bug. Build tools and runtime checks help us find problems that output alone does not reveal.
