add_executable(BinarySearchTreeTests
    tests/test_main.cpp
    tests/basic_tests.cpp
    tests/custom_tests.cpp
)

target_include_directories(BinarySearchTreeTests PRIVATE include)
add_test(NAME BinarySearchTreeTests COMMAND BinarySearchTreeTests)
