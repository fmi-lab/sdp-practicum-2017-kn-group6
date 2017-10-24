#include "../../lib/doctest.h"
#include <string>
#include <stack>

using namespace std;

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double apply(char operation, double v1, double v2) {
    switch (operation) {
        case '+': return v1 + v2;
        case '-': return v1 - v2;
        case '*': return v1 * v2;
        case '/': return v1 / v2;
        default:  return 0;
    }
}

int to_digit(char c) {
    return c - 48;
}

double compute_postfix(const string& expression) {
    stack<double> values;

    for (char token: expression) {
        if (is_operator(token)) {
            double right = values.top(); values.pop();
            double left = values.top(); values.pop();
            values.push(apply(token, left, right));
        } else if (isdigit(token)) {
            values.push(to_digit(token));
        }
    }

    return values.top();
}

TEST_CASE("compute postfix expression") {
    CHECK(4 == compute_postfix("3 4 - 5 +"));
}
