#include <string>
#include <vector>
#include "../../lib/doctest.h"
#include "../../lib/list/linked_list.hpp"
#include "stack.cpp"

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
