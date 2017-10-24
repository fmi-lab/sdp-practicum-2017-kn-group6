#include "../../lib/doctest.h"
#include "tribonacci_iterator.cpp"

int count_ways_to_solve(int n_problems) {
    TribonacciIterator counter(1, 1, 2);

    for (int i = 1; i < n_problems; ++i, ++counter);

    return *counter;
}

TEST_CASE("count ways to solve tasks from task #1 to task #N") {
    CHECK(7 == count_ways_to_solve(5));
    CHECK(81 == count_ways_to_solve(9));
    CHECK(10609 == count_ways_to_solve(17));
    CHECK(66012 == count_ways_to_solve(20));
}
