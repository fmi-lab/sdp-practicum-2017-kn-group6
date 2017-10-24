#include "../../lib/doctest.h"
#include "../../lib/list/linked_list.hpp"

template <typename T>
class Stack {
private:
    LinkedList<T> list;

public:
    bool empty() const {
        return list.empty();
    }

    const std::size_t size() const {
        return list.size();
    }

    void push(const T& item) {
        list.push_front(item);
    }

    bool pop() {
        return list.pop_front();
    }

    T top() const {
        assert(!empty());
        return list.front();
    }
};

TEST_CASE("stack") {
    Stack<int> stack;
    CHECK(stack.empty());

    SUBCASE("push") {
        int SIZE = 1000;
        for (int i = 0; i < SIZE; ++i) {
            stack.push(i);
            CHECK(stack.size() == i + 1);
        }
    }

    SUBCASE("pop") {
        int SIZE = 1000;
        for (int i = 0; i < SIZE; ++i) {
            stack.push(i);
            CHECK(stack.size() == i + 1);
        }

        for (int i = 0; i < SIZE; ++i) {
            CHECK(stack.top() == SIZE - i - 1);
            CHECK(stack.pop());
            CHECK(stack.size() == SIZE - i - 1);
        }

        CHECK(!stack.pop());
    }
}
