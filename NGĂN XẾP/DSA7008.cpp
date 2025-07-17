#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

bool isRightAssociative(char op) {
    return (op == '^');
}

string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix = "";
    
    for (char c : infix) {
        if (isalnum(c)) {
            // Operand - add to output
            postfix += c;
        }
        else if (c == '(') {
            // Left parenthesis - push to stack
            operatorStack.push(c);
        }
        else if (c == ')') {
            // Right parenthesis - pop until left parenthesis
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty()) {
                operatorStack.pop(); // Remove the '('
            }
        }
        else if (isOperator(c)) {
            // Operator - handle precedence and associativity
            while (!operatorStack.empty() && 
                   operatorStack.top() != '(' &&
                   (getPrecedence(operatorStack.top()) > getPrecedence(c) ||
                    (getPrecedence(operatorStack.top()) == getPrecedence(c) && !isRightAssociative(c)))) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }
    
    // Pop remaining operators
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    
    return postfix;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string infix;
        cin >> infix;
        cout << infixToPostfix(infix) << endl;
    }
    
    return 0;
} 