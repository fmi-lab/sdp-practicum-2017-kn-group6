#include "../../lib/doctest.h"
#include <string>
#include <stack>

using namespace std;

bool is_operator2(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infix_to_postfix(const string& expression) {
    string postfix;
    stack<char> operators;

    for (char token: expression) {
        // TODO: reuse is_operator
        if (is_operator2(token)) {
            operators.push(token);
        } else if (isdigit(token)) {
            postfix.push_back(token);
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (operators.top() != '(') {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

TEST_CASE("convert infix to postfix expression") {
    CHECK("34-5+" == infix_to_postfix("(3 - 4) + 5"));
    CHECK("32-" == infix_to_postfix("3 - 2"));
//    CHECK("532*+" == infix_to_postfix("3 * 2 + 5"));
    CHECK("93-3/" == infix_to_postfix("(9 - 3) / 3"));
}
