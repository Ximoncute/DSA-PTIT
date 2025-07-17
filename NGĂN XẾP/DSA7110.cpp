#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOpeningBracket(char c) {
    return (c == '(' || c == '[' || c == '{');
}

bool isClosingBracket(char c) {
    return (c == ')' || c == ']' || c == '}');
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isValidBracketSequence(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (isOpeningBracket(c)) {
            st.push(c);
        }
        else if (isClosingBracket(c)) {
            if (st.empty()) {
                return false; // No matching opening bracket
            }
            
            char top = st.top();
            st.pop();
            
            if (!isMatchingPair(top, c)) {
                return false; // Mismatched bracket types
            }
        }
    }
    
    // Stack should be empty for valid sequence
    return st.empty();
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        if (isValidBracketSequence(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
} 