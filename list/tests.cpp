#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>
#include "../doctest.h"

#include "linked_list.hpp"
#include "library.hpp"

typedef LinkedList<int> IntList;

TEST_CASE("lists can be created") {
    IntList list;

    REQUIRE(list.size() == 0);

    SUBCASE("with copy constructors") {
        const int SIZE = 100;
        for (int i = 0; i < SIZE; ++i) {
            list.push_back(i);
            CHECK(list.size() == i + 1);
        }

        IntList copy = list;

        CHECK(list.size() == copy.size());
        for (int i = 0; i < SIZE; ++i) {
            CHECK(list.get(i) == copy.get(i));
        }
    }

    SUBCASE("with std::initializer_list") {
        IntList ints = {15, 87, 29, 26, 9};

        CHECK(ints.size() == 5);
        CHECK(ints.get(0) == 15);
        CHECK(ints.get(1) == 87);
        CHECK(ints.get(2) == 29);
        CHECK(ints.get(3) == 26);
        CHECK(ints.get(4) == 9);
    }
}

TEST_CASE("elements can be added to lists with") {
    IntList list;

    REQUIRE(list.size() == 0);

    SUBCASE("push_front") {
        list.push_front(1);
        CHECK(list.size() == 1);
        list.push_front(2);
        CHECK(list.size() == 2);
    }

    SUBCASE("push_back") {
        list.push_back(1);
        CHECK(list.size() == 1);
        list.push_back(2);
        CHECK(list.size() == 2);
    }

    SUBCASE("insert") {
        list.insert(0, 10);
        CHECK(list.get(0) == 10);
        CHECK(list.size() == 1);
        list.insert(0, 12);
        CHECK(list.get(0) == 12);
        CHECK(list.size() == 2);

        list.insert(2, 9);
        CHECK(list.get(2) == 9);
        CHECK(list.size() == 3);
        list.insert(1, 4);
        CHECK(list.get(1) == 4);
        CHECK(list.size() == 4);
    }
}

TEST_CASE("elements can be removed from lists with") {
    const int SIZE = 100;
    IntList list;

    for (int i = 0; i < SIZE; ++i) {
        list.push_back(i);
        CHECK(list.size() == i + 1);
    }

    SUBCASE("pop_front") {
        while (!list.empty()) {
            CHECK(list.pop_front());
        }
        CHECK(list.size() == 0);
        CHECK(list.empty());
        CHECK(!list.pop_front());
    }

    SUBCASE("pop_back") {
        while (!list.empty()) {
            CHECK(list.pop_back());
        }
        CHECK(list.size() == 0);
        CHECK(list.empty());
        CHECK(!list.pop_back());
    }

    SUBCASE("erase") {
        CHECK(list.erase(1));
        CHECK(list.size() == SIZE - 1);
        CHECK(list.get(1) == 2);

        CHECK(list.erase(3));
        CHECK(list.size() == SIZE - 2);
        CHECK(list.get(3) == 5);

        CHECK(list.erase(3));
        CHECK(list.size() == SIZE - 3);
        CHECK(list.get(3) == 6);
    }

    SUBCASE("clear") {
        CHECK(list.clear());
        CHECK(list.size() == 0);
        CHECK(list.empty());
        CHECK(!list.clear());
    }
}

TEST_CASE("list elements can be accessed with") {
    const int SIZE = 100;
    IntList list;

    for (int i = 0; i < SIZE; ++i) {
        list.push_back(i);
        CHECK(list.size() == i + 1);
    }

    SUBCASE("get") {
        for (int i = 0; i < SIZE; ++i) {
            CHECK(list.get(i) == i);
        }
    }

    SUBCASE("front") {
        for (int i = 0; i < SIZE; ++i) {
            CHECK(list.front() == i);
            CHECK(list.pop_front());
        }
    }

    SUBCASE("back") {
        for (int i = 0; i < SIZE; ++i) {
            CHECK(list.back() == SIZE - i - 1);
            CHECK(list.pop_back());
        }
    }
}

TEST_CASE("count occurrences of element x") {
    SUBCASE("count") {
        IntList list;
        const int SIZE = 10;
        for (int i = 0; i < SIZE; ++i) {
            list.push_front(i);
        }

        CHECK(count(list.head(), 1) == 1);
    }
}

//TEST_CASE("list library") {
//    SUBCASE("concat") {
//        IntList list1 = {1, 2, 3, 4, 5, 6};
//        IntList list2 = {7, 8, 9, 10};
//
//        Node<int>* list = concat<int>(list1.head(), list2.head());
//
//        Node<int>* head = list;
//        for (int i = 1; i <= 10; ++i) {
//            CHECK(head->_value == i);
//            head = head->_next;
//        }
//        CHECK(head == nullptr);
//    }
//}
