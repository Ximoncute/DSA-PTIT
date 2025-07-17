#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
    int n = s.length();
    if (n == 0) return 0;
    
    stack<int> st;
    vector<bool> matched(n, false);
    
    // Mark all matched parentheses
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else { // s[i] == ')'
            if (!st.empty()) {
                int openIndex = st.top();
                st.pop();
                matched[i] = true;
                matched[openIndex] = true;
            }
        }
    }
    
    // Find the longest consecutive sequence of matched parentheses
    int maxLength = 0;
    int currentLength = 0;
    
    for (int i = 0; i < n; i++) {
        if (matched[i]) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 0;
        }
    }
    
    return maxLength;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        cout << longestValidParentheses(s) << endl;
    }
    
    return 0;
} 