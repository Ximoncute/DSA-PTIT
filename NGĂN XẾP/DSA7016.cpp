#include <iostream>
#include <stack>
#include <string>
using namespace std;

string findSmallestNumber(string pattern) {
    int n = pattern.length();
    string result = "";
    stack<int> st;
    
    // Process each character in the pattern
    for (int i = 0; i <= n; i++) {
        // Push current number (1-indexed) to stack
        st.push(i + 1);
        
        // If we encounter 'I' or reach the end, pop all elements from stack
        if (i == n || pattern[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string pattern;
        cin >> pattern;
        cout << findSmallestNumber(pattern) << endl;
    }
    
    return 0;
} 