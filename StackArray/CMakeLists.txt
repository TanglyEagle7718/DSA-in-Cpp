add_executable(StackArrayTests
    tests/test_main.cpp
    tests/basic_tests.cpp
    tests/custom_tests.cpp
)

target_include_directories(StackArrayTests PRIVATE include)
add_test(NAME StackArrayTests COMMAND StackArrayTests)
