#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

bool isOperator(string token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

long long evaluatePostfix(string expression) {
    stack<long long> st;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        if (isOperator(token)) {
            // Pop two operands (note the order!)
            long long operand2 = st.top(); st.pop();
            long long operand1 = st.top(); st.pop();
            
            long long result;
            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "/") {
                result = operand1 / operand2;
            }
            
            st.push(result);
        } else {
            // It's a number (possibly negative or multi-digit)
            long long num = stoll(token);
            st.push(num);
        }
    }
    
    return st.top();
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        cin.ignore(); // To ignore the newline after reading n
        
        string expression;
        getline(cin, expression);
        
        cout << evaluatePostfix(expression) << endl;
    }
    
    return 0;
} 