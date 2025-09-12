# Memory Leak Lesson Demo

This program implements a resizing `DynamicArray`. Resizing cleans up the old array, but the class intentionally has no destructor. When the object goes out of scope, its final heap array leaks.

```bash
make
./memory_leak
```

The output is correct, but a Linux memory checker reports the leak:

```bash
valgrind --leak-check=full --error-exitcode=1 ./memory_leak
```

Fix the leak by adding a destructor to `DynamicArray` that calls `delete[] data_;`.
