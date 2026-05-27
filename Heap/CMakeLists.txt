add_executable(HeapTests
    tests/test_main.cpp
    tests/basic_tests.cpp
    tests/custom_tests.cpp
)

target_include_directories(HeapTests PRIVATE include)
add_test(NAME HeapTests COMMAND HeapTests)
