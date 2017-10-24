#include "../../lib/doctest.h"
#include <vector>

class TribonacciIterator {
private:
    int a;
    int b;
    int c;

    void generateNext(int old_a, int old_b, int old_c) {
        a = old_b;
        b = old_c;
        c = old_a + old_b + old_c;
    }

    void generatePrevious(int curr_a, int curr_b, int curr_c) {
        a = curr_c - curr_b - curr_a;
        b = curr_c - curr_b - a;
        c = curr_c - b - a;
    }
public:
    // needed for problem 3, so that we can change the base
    TribonacciIterator(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}

    TribonacciIterator() : TribonacciIterator(0, 0, 1) {}

    TribonacciIterator& operator++() {
        generateNext(a, b, c);
        return *this;
    }

    TribonacciIterator operator++(int) {
        TribonacciIterator previous = *this;
        generateNext(a, b, c);
        return previous;
    }

    TribonacciIterator& operator--() {
        generatePrevious(a, b, c);
        return *this;
    }

    TribonacciIterator operator--(int) {
        TribonacciIterator previous = *this;
        generatePrevious(a, b, c);
        return previous;
    }

    int operator*() const {
        return a;
    }

    TribonacciIterator& operator->() {
        return *this;
    }

    bool operator==(const TribonacciIterator& other) const {
        return a == other.a && b == other.b && c == other.c;
    }

    bool operator!=(const TribonacciIterator& other) const {
        return !(*this == other);
    }
};

TEST_CASE("TribonacciIterator") {
    std::vector<int> numbers = {0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274};
    TribonacciIterator iter;

    SUBCASE("traversal with prefix operator++") {
        CHECK(numbers[0] == *iter);
        for (int i = 1; i < numbers.size(); ++i) {
            CHECK(*(++iter) == numbers[i]);
        }
    }

    SUBCASE("traversal with prefix operator--") {
        for (int i = 1; i < numbers.size(); ++i) {
            iter++;
        };

        for (int i = numbers.size() - 1; i >= 0; --i) {
            CHECK(numbers[i] == *iter);
            --iter;
        }
    }
}
