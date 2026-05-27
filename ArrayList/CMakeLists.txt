add_executable(ArrayListTests
    tests/test_main.cpp
    tests/basic_tests.cpp
    tests/custom_tests.cpp
)

target_include_directories(ArrayListTests PRIVATE include)
add_test(NAME ArrayListTests COMMAND ArrayListTests)
