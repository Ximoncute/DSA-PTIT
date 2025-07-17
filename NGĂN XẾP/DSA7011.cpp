#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToPrefix(string postfix) {
    stack<string> st;
    
    // Process from left to right
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (isOperator(c)) {
            // Pop two operands
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            
            // Create prefix expression: operator operand1 operand2
            string prefix = c + operand1 + operand2;
            st.push(prefix);
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
        cout << postfixToPrefix(postfix) << endl;
    }
    
    return 0;
} 