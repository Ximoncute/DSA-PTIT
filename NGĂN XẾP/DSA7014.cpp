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

int evaluatePrefix(string prefix) {
    stack<int> st;
    
    // Process from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        if (isDigit(c)) {
            // Convert character to integer and push
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            // Pop two operands (note the order for prefix!)
            int operand1 = st.top(); st.pop();
            int operand2 = st.top(); st.pop();
            
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
        string prefix;
        cin >> prefix;
        cout << evaluatePrefix(prefix) << endl;
    }
    
    return 0;
} 