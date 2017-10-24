#include "../../lib/doctest.h"


class OddIterator {
private:
    int number;

public:
    OddIterator() : number(1) {}

    OddIterator& operator++() {
        number += 2;
        return *this;
    }

    OddIterator operator++(int) {
        OddIterator previous = *this;
        number += 2;
        return previous;
    }

    int operator*() {
        return number;
    }

    OddIterator& operator->() {
        return *this;
    }

    bool operator==(const OddIterator& other) const {
        return number == other.number;
    }

    bool operator!=(const OddIterator& other) const {
        return !(*this == other);
    }

    operator bool() const { // this iterator is infinite
        return true;
    }

    bool operator!() const {
        return false;
    }
};

TEST_CASE("OddIterator") {
    SUBCASE("traversal with postfix increment") {
        const int SIZE = 100;
        OddIterator iter;
        for (int i = 1; i < SIZE; ++i) {
            CHECK(*(iter++) == 2 * (i - 1) + 1);
            CHECK(*iter == 2 * i + 1);
        }
    }
}
