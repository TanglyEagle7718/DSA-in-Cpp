add_executable(QueueArrayTests
    tests/test_main.cpp
    tests/basic_tests.cpp
    tests/custom_tests.cpp
)

target_include_directories(QueueArrayTests PRIVATE include)
add_test(NAME QueueArrayTests COMMAND QueueArrayTests)
