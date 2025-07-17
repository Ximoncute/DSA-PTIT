#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool isOperator(string token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

long long evaluatePrefix(vector<string>& tokens) {
    stack<long long> st;
    
    // Process tokens from right to left
    for (int i = tokens.size() - 1; i >= 0; i--) {
        string token = tokens[i];
        
        if (isOperator(token)) {
            // Pop two operands (note the order for prefix!)
            long long operand1 = st.top(); st.pop();
            long long operand2 = st.top(); st.pop();
            
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
        
        string line;
        getline(cin, line);
        
        // Parse tokens from the line
        vector<string> tokens;
        stringstream ss(line);
        string token;
        
        while (ss >> token) {
            tokens.push_back(token);
        }
        
        cout << evaluatePrefix(tokens) << endl;
    }
    
    return 0;
} 