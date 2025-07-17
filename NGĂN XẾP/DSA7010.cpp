#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToPostfix(string prefix) {
    stack<string> st;
    
    // Process from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        if (isOperator(c)) {
            // Pop two operands
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();
            
            // Create postfix expression: operand1 operand2 operator
            string postfix = operand1 + operand2 + c;
            st.push(postfix);
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
        string prefix;
        cin >> prefix;
        cout << prefixToPostfix(prefix) << endl;
    }
    
    return 0;
} 