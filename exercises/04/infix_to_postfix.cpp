#include "../../lib/doctest.h"
#include <string>
#include <stack>

using namespace std;

bool is_operator2(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int presedence(char operation) {
    switch (operation) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default:  return 0;
    }
}

string infix_to_postfix(const string& expression) {
    string postfix;
    stack<char> operators;

    for (char token: expression) {
        // TODO: reuse is_operator
        if (is_operator2(token)) {
            while (!operators.empty() && presedence(operators.top()) >= presedence(token)) {
                postfix.push_back(operators.top());
                operators.pop();
            }
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
    CHECK("32*5+" == infix_to_postfix("3 * 2 + 5"));
    CHECK("93-3/" == infix_to_postfix("(9 - 3) / 3"));
    CHECK("23*42/+" == infix_to_postfix("2 * 3 + 4 / 2"));
    CHECK("5711+-/3*211++-" == infix_to_postfix("((5 / (7 - (1 + 1))) * 3) - (2 + (1 + 1))"));
}
