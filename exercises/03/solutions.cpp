#include <string>
#include <vector>
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
    TribonacciIterator() : a(1), b(1), c(2) {}

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
    std::vector<int> numbers = {1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274};
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
