add_executable(CircularLinkedListTests
    tests/test_main.cpp
    tests/basic_tests.cpp
    tests/custom_tests.cpp
)

target_include_directories(CircularLinkedListTests PRIVATE include)
add_test(NAME CircularLinkedListTests COMMAND CircularLinkedListTests)
