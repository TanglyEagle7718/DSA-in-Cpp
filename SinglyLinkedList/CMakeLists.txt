add_executable(SinglyLinkedListTests
    tests/test_main.cpp
    tests/basic_tests.cpp
    tests/custom_tests.cpp
    tests/full_tests.cpp
)

target_include_directories(SinglyLinkedListTests PRIVATE include)
add_test(NAME SinglyLinkedListTests COMMAND SinglyLinkedListTests)
