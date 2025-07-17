#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix) {
    stack<string> st;
    
    // Process from left to right
    for (char c : postfix) {
        if (isOperator(c)) {
            // Pop two operands
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            
            // Create infix expression with parentheses
            string infix = "(" + operand1 + c + operand2 + ")";
            st.push(infix);
        } else {
            // Operand - push to stack
            st.push(string(1, c));
        }
    }
    
    return st.top();
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string postfix;
        cin >> postfix;
        cout << postfixToInfix(postfix) << endl;
    }
    
    return 0;
} 