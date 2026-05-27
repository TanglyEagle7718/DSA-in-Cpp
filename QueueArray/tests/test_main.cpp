#include <exception>
#include <iostream>

void run_basic_tests();
void run_custom_tests();

int main() {
    try {
        run_basic_tests();
        run_custom_tests();
        std::cout << "QueueArrayTests: PASS\n";
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "QueueArrayTests: FAIL - " << ex.what() << "\n";
    } catch (...) {
        std::cerr << "QueueArrayTests: FAIL - unknown exception\n";
    }

    return 1;
}
