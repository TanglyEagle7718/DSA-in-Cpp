#include <exception>
#include <iostream>

void run_basic_tests();
void run_custom_tests();

int main() {
    try {
        run_basic_tests();
        run_custom_tests();
        std::cout << "BinarySearchTreeTests: PASS\n";
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "BinarySearchTreeTests: FAIL - " << ex.what() << "\n";
    } catch (...) {
        std::cerr << "BinarySearchTreeTests: FAIL - unknown exception\n";
    }

    return 1;
}
