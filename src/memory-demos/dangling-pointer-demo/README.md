# Dangling Pointer Memory Demo

This program intentionally returns the address of a local array. That array no longer exists after the function returns, but the caller writes values through the invalid pointer anyway.

```bash
make
./dangling_pointer
```

The compiler should warn about returning an address on the stack. Running the program is undefined behavior: it may print a value, print garbage, or crash.
