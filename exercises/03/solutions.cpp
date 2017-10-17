#include <string>
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

bool parenthesesMatch(char left, char right) {
    return left == '(' && right == ')' ||
           left == '[' && right == ']' ||
           left == '{' && right == '}' ||
           left == '<' && right == '>';
}

bool isBalanced(const std::string& expression) {
    Stack<char> parentheses;

    for (char character: expression) {
        switch (character) {
            case '(':
            case '[':
            case '{':
            case '<':
                parentheses.push(character);
                break;
            case ')':
            case ']':
            case '}':
            case '>':
                if (parentheses.empty() || !parenthesesMatch(parentheses.top(), character)) {
                    return false;
                }
                parentheses.pop();
                break;
            default: break;
        }
    }

    return true;
}

TEST_CASE("matching parentheses") {
    SUBCASE("positive tests") {
        CHECK(isBalanced("{()<class T>}"));
        CHECK(isBalanced("(a+2)[<>{}]()"));
        CHECK(isBalanced("(<>{<[1, 2]()>(()[])})"));
    }

    SUBCASE("negative tests") {
        CHECK_FALSE(isBalanced("(>_<)"));
        CHECK_FALSE(isBalanced("(x) => {x + 1}"));
        CHECK_FALSE(isBalanced("}>)"));
        CHECK_FALSE(isBalanced("(])[]"));
        CHECK_FALSE(isBalanced("(<>{)}"));
    }
}

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
