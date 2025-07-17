#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int evaluatePostfix(string postfix) {
    stack<int> st;
    
    // Process from left to right
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (isDigit(c)) {
            // Convert character to integer and push
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            // Pop two operands (note the order!)
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            
            int result;
            switch (c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            
            st.push(result);
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
        cout << evaluatePostfix(postfix) << endl;
    }
    
    return 0;
} 