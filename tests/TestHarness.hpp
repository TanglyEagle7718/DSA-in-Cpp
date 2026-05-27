#ifndef TEST_HARNESS_HPP
#define TEST_HARNESS_HPP

#include <exception>
#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

struct TestCase {
    std::string name;
    std::function<void()> test_fn;
};

class TestSuite {
public:
    explicit TestSuite(std::string suite_name)
        : suite_name_(std::move(suite_name)) {}

    void add(const std::string& test_name, const std::function<void()>& test_fn) {
        tests_.push_back({test_name, test_fn});
    }

    int run() const {
        std::cout << "Running suite: " << suite_name_ << "\n";
        int passed = 0;

        for (const auto& test : tests_) {
            try {
                test.test_fn();
                std::cout << "  [PASS] " << test.name << "\n";
                ++passed;
            } catch (const std::exception& ex) {
                std::cout << "  [FAIL] " << test.name << " - " << ex.what() << "\n";
            } catch (...) {
                std::cout << "  [FAIL] " << test.name << " - unknown exception\n";
            }
        }

        std::cout << "Summary: " << passed << "/" << tests_.size() << " tests passed\n";
        return passed == static_cast<int>(tests_.size()) ? 0 : 1;
    }

private:
    std::string suite_name_;
    std::vector<TestCase> tests_;
};

#define EXPECT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            std::ostringstream oss; \
            oss << "EXPECT_TRUE failed: " #condition; \
            throw std::runtime_error(oss.str()); \
        } \
    } while (false)

#define EXPECT_EQ(actual, expected) \
    do { \
        if (!((actual) == (expected))) { \
            std::ostringstream oss; \
            oss << "EXPECT_EQ failed: " #actual " != " #expected; \
            throw std::runtime_error(oss.str()); \
        } \
    } while (false)

#endif
