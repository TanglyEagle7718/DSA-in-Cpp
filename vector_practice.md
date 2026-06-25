# C++ DSA Practice: Custom Templated Vector

This document contains a structured practice assignment for implementing a custom templated `Vector` (dynamic array) in C++. It includes a prompt that you can feed into another LLM to set up the skeleton files and a basic test suite, along with guidelines for completing the implementation.

---

## 🤖 LLM Prompt for Code Generation
*Copy and paste the prompt below into another LLM to generate the starter skeleton files and basic test suite.*

```text
Act as a senior C++ tutor. I want to practice writing a custom templated Vector class (dynamic array) to master memory management, copy/move semantics, and templates.

Please generate two files based on the specifications below:
1. `Vector.hpp` - A templated class header file with empty constructors, destructors, and basic member function stubs. Do not implement the logic yet; leave them empty or return placeholder values.
2. `test_vector.cpp` - A main file containing a basic test suite using `assert` for verification. It should ONLY test normal/happy-path functionality (e.g., adding elements, basic capacity resizing, accessing elements). Do NOT include tests for edge cases, self-assignment, or exception handling. Leave those for me to implement.

Specifications for Vector.hpp:
- The class must be named `Vector` inside the namespace `dsa`.
- Template parameter: `typename T`.
- Internal state:
  - `T* data_` - pointer to the underlying array.
  - `size_t capacity_` - current allocated capacity.
  - `size_t size_` - current number of elements.
- Methods to stub out:
  - Default constructor, parameterized constructor (initializing with a specific size and default value).
  - Rule of 5: Destructor, Copy Constructor, Copy Assignment Operator, Move Constructor, Move Assignment Operator.
  - Modifiers: `push_back(const T&)`, `pop_back()`, `reserve(size_t)`, `clear()`.
  - Accessors: `operator[](size_t)`, `at(size_t)`, `size()`, `capacity()`, `empty()`.

Provide the files in clear, copyable markdown code blocks.
```

---

## 📄 Starter Code Reference

If you want to create the files manually, here is the reference template code and the basic test suite.

### 1. `Vector.hpp`

```cpp
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <utility>

namespace dsa {

template <typename T>
class Vector {
public:
    // --- Constructors and Destructor ---
    
    // Default constructor
    Vector() : data_(nullptr), capacity_(0), size_(0) {}

    // Parameterized constructor
    explicit Vector(size_t initial_capacity) {
        // TODO: Implement
    }

    // Destructor
    ~Vector() {
        // TODO: Implement
    }

    // --- Copy and Move Semantics (Rule of 5) ---

    // Copy constructor
    Vector(const Vector& other) {
        // TODO: Implement
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other) {
        // TODO: Implement
        return *this;
    }

    // Move constructor
    Vector(Vector&& other) noexcept {
        // TODO: Implement
    }

    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept {
        // TODO: Implement
        return *this;
    }

    // --- Element Access ---

    T& operator[](size_t index) {
        // TODO: Implement
        static T dummy; // Placeholder
        return dummy;
    }

    const T& operator[](size_t index) const {
        // TODO: Implement
        static T dummy; // Placeholder
        return dummy;
    }

    T& at(size_t index) {
        // TODO: Implement
        static T dummy; // Placeholder
        return dummy;
    }

    const T& at(size_t index) const {
        // TODO: Implement
        static T dummy; // Placeholder
        return dummy;
    }

    // --- Capacity ---

    size_t size() const noexcept {
        // TODO: Implement
        return 0;
    }

    size_t capacity() const noexcept {
        // TODO: Implement
        return 0;
    }

    bool empty() const noexcept {
        // TODO: Implement
        return true;
    }

    // --- Modifiers ---

    void push_back(const T& value) {
        // TODO: Implement
    }

    void pop_back() {
        // TODO: Implement
    }

    void reserve(size_t new_capacity) {
        // TODO: Implement
    }

    void clear() noexcept {
        // TODO: Implement
    }

private:
    T* data_ = nullptr;
    size_t capacity_ = 0;
    size_t size_ = 0;
};

} // namespace dsa

#endif // VECTOR_HPP
```

### 2. `test_vector.cpp` (Basic Test Suite)

```cpp
#include "Vector.hpp"
#include <iostream>
#include <cassert>
#include <string>

void test_basic_construction() {
    dsa::Vector<int> vec;
    assert(vec.size() == 0);
    assert(vec.capacity() == 0);
    assert(vec.empty());
    std::cout << "test_basic_construction passed!\n";
}

void test_push_and_pop() {
    dsa::Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    assert(vec.size() == 3);
    assert(vec.capacity() >= 3);
    assert(!vec.empty());
    
    assert(vec[0] == 10);
    assert(vec[1] == 20);
    assert(vec[2] == 30);

    vec.pop_back();
    assert(vec.size() == 2);
    assert(vec[0] == 10);
    assert(vec[1] == 20);

    std::cout << "test_push_and_pop passed!\n";
}

void test_reserve() {
    dsa::Vector<std::string> vec;
    vec.reserve(10);
    assert(vec.capacity() == 10);
    assert(vec.size() == 0);

    vec.push_back("Hello");
    vec.push_back("World");
    assert(vec.size() == 2);
    assert(vec.capacity() == 10);
    assert(vec[0] == "Hello");
    assert(vec[1] == "World");
    std::cout << "test_reserve passed!\n";
}

int main() {
    std::cout << "Running basic Vector tests...\n";
    test_basic_construction();
    test_push_and_pop();
    test_reserve();
    std::cout << "All basic tests passed successfully!\n";
    return 0;
}
```

---

## 🛠️ Your Goal: Write Edge Case Tests

The basic test suite above only verifies normal behavior. To truly build a robust data structure, you must implement the edge cases yourself. Once you have implemented the `Vector` methods, extend `test_vector.cpp` to include the following test suites:

### 1. Out-of-Bounds Bounds Access (`at()`)
Test that calling `.at()` with an out-of-bounds index correctly throws `std::out_of_range`.
```cpp
void test_out_of_bounds() {
    dsa::Vector<int> vec;
    vec.push_back(5);
    try {
        vec.at(1); // Should throw
        assert(false && "Expected std::out_of_range");
    } catch (const std::out_of_range& e) {
        // Success
    }
}
```

### 2. Copy Semantics (Deep Copy & Self-Assignment)
Test that copying a vector allocates a completely separate memory block (deep copy) and that self-assignment (e.g., `vec = vec`) is handled safely.
```cpp
void test_copy_semantics() {
    dsa::Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    dsa::Vector<int> v2 = v1; // Copy constructor
    assert(v2.size() == 2);
    v2[0] = 99;
    assert(v1[0] == 1); // Check deep copy: v1 remains unchanged

    v1 = v1; // Self-assignment
    assert(v1.size() == 2 && v1[0] == 1);
}
```

### 3. Move Semantics (Resource Theft & Null State)
Test that moving a vector correctly transfers ownership of the resources and leaves the moved-from vector in a valid, empty state.
```cpp
void test_move_semantics() {
    dsa::Vector<int> v1;
    v1.push_back(100);

    dsa::Vector<int> v2 = std::move(v1); // Move constructor
    assert(v2.size() == 1);
    assert(v2[0] == 100);
    assert(v1.empty()); // Moved-from state should be empty/null
}
```

### 4. Shrinking / Popping Empty Vectors
Test how `pop_back()` and `clear()` behave when the vector is empty or when we clear elements.
- Does calling `pop_back()` on an empty vector cause a crash or is it handled?
- Does `clear()` properly call destructors of complex types without deallocating capacity?

---

## 🚀 How to Compile and Run
Use a C++17 compatible compiler (like `g++` or `clang++`):

```bash
g++ -std=c++17 -Wall -Wextra test_vector.cpp -o test_vector
./test_vector
```
