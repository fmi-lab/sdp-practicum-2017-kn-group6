#include "../../lib/doctest.h"
#include "binary_heap.hpp"
#include <vector>
#include <iostream>

using namespace std;

void heapSort(vector<int>& numbers) {
    BinaryHeap heap;
    for (int i = 0; i < numbers.size(); ++i) {
        heap.push(numbers[i]);
    }

    for (int i = 0; i < numbers.size(); ++i) {
        numbers[i] = heap.top();
        heap.pop();
    }
}

TEST_CASE("heap sort") {
    std::vector<int> numbers {5, 3, 1, 2, 4};

    heapSort(numbers);

    CHECK(numbers[0] == 1);
    CHECK(numbers[1] == 2);
    CHECK(numbers[2] == 3);
    CHECK(numbers[3] == 4);
    CHECK(numbers[4] == 5);
}

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
