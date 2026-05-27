add_executable(DoublyLinkedListTests
    tests/test_main.cpp
    tests/basic_tests.cpp
    tests/custom_tests.cpp
)

target_include_directories(DoublyLinkedListTests PRIVATE include)
add_test(NAME DoublyLinkedListTests COMMAND DoublyLinkedListTests)
