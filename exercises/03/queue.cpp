#include "../../lib/doctest.h"
#include "stack.cpp"

template <typename T>
class Queue {
private:
    Stack<T> input;
    Stack<T> output;
public:
    const std::size_t size() const {
        return input.size() + output.size();
    }

    const bool empty() const {
        return size() == 0;
    }

    void enqueue(const T& item) {
        input.push(item);
    }

    T front() {
        assert(!empty());
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool dequeue() {
        if (empty()) {
            return false;
        }

        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.pop();
    }
};


TEST_CASE("queue") {
    Queue<int> queue;
    CHECK(queue.empty());

    SUBCASE("enqueue") {
        int SIZE = 1000;
        for (int i = 0; i < SIZE; ++i) {
            queue.enqueue(i);
            CHECK(queue.size() == i + 1);
        }
    }

    SUBCASE("dequeue") {
        int SIZE = 1000;
        for (int i = 0; i < SIZE; ++i) {
            queue.enqueue(i);
            CHECK(queue.size() == i + 1);
        }

        for (int i = 0; i < SIZE; ++i) {
            CHECK(queue.front() == i);
            CHECK(queue.dequeue());
            CHECK(queue.size() == SIZE - i - 1);
        }

        CHECK(!queue.dequeue());
    }
}
