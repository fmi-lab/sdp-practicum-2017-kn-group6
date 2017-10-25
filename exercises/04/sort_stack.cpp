#include "../../lib/doctest.h"
#include <stack>
#include <climits>

using namespace std;

void sort(stack<int>& s) {
    stack<int> helper;

    for (int n = s.size(); n > 0; --n) {
        int minimum = INT_MAX;

        // find the minimum by popping
        for (int j = 0; j < n; ++j) {
            int item = s.top();
            minimum = min(minimum, item);
            helper.push(item);
            s.pop();
        }

        s.push(minimum);

        // push back the minimum in its correct position
        bool is_minimum_passed = false;
        for (int j = 0; j < n; ++j) {
            int item = helper.top();

            if (!is_minimum_passed && item == minimum) {
                is_minimum_passed = true;
            } else {
                s.push(item);
            }

            helper.pop();
        }
    }
}

TEST_CASE("sorting a stack") {
    SUBCASE("a sorted stack stays sorted") {
        const int SIZE = 3;
        stack<int> s;

        for (int i = 1; i <= SIZE; ++i) {
            s.push(i);
        }

        sort(s);

        for (int i = SIZE; i > 0; --i) {
            CHECK(i == s.top());
            s.pop();
        }
    }

    SUBCASE("a stack in descending order can be sorted in ascending order") {
        const int SIZE = 30;
        stack<int> s;

        for (int i = SIZE; i > 0; --i) {
            s.push(i);
        }

        sort(s);

        for (int i = SIZE; i > 0; --i) {
            CHECK(i == s.top());
            s.pop();
        }
    }
}
