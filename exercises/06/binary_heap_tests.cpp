#include "../../lib/doctest.h"
#include "binary_heap.hpp"
#include <vector>
#include <iostream>

using namespace std;

TEST_CASE("binary heap") {
    SUBCASE("make heap") {
        std::vector<int> numbers {9, 4, 12, 88, -2, 15, 3, 42, -114, 12, 3};
        BinaryHeap heap(numbers);

        CHECK(numbers.size() == heap.size());
        CHECK(heap.is_min_heap());

        int min = heap.top();
        while (!heap.empty()) {
            CHECK(min <= heap.top());
            min = heap.top();
            CHECK(heap.pop());
            CHECK(heap.is_min_heap());
        }

        CHECK(0 == heap.size());
        CHECK(!heap.pop());
    }
}
