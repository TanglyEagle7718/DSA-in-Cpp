# DSA in C++ Practice Scaffold

This repository contains template implementations and test scaffolding for the following data structures:

- ArrayList
- Singly Linked List
- Doubly Linked List
- Circular Linked List
- Stack (array based)
- Queue (array based)
- Binary Search Tree
- Heap (+ standalone `heapify` function)

All generated data structure functions are intentionally left unimplemented and currently throw `std::logic_error`. This is by design for practice.

## Project Layout

Each data structure has its own folder with:

- `include/` for headers
- `src/` for implementation files (placeholder)
- `tests/` for test files

Tests are split into:

- `basic_tests.cpp`: basic functionality tests (no edge cases)
- `custom_tests.cpp`: your extension point to add edge-case tests
- `test_main.cpp`: runner that invokes both basic and custom tests

## Build With CMake + Make

From the repository root:

```bash
cmake -S . -B build
cmake --build build
```

This uses CMake to generate Makefiles and then builds all test executables.

## Run Tests

Run all tests through CTest:

```bash
cd build
ctest --output-on-failure
```

Or run a single test executable directly, for example:

```bash
./build/ArrayList/ArrayListTests
```

## Add Custom Edge-Case Tests

Open each module's `tests/custom_tests.cpp` and add test logic inside `run_custom_tests()`.

Suggested edge-case categories (for your own custom tests):

- Empty structure operations
- Out-of-bounds access
- Duplicate values
- Capacity growth and wrap-around behavior (array-backed structures)
- Tree/heap behavior after many inserts/removes

## Notes

- Basic tests currently describe expected behavior and will fail until you implement methods.
- After implementing one data structure, rerun only its test binary for fast feedback.
