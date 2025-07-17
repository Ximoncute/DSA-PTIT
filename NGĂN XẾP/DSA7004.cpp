#include <iostream>
#include <string>
using namespace std;

int minFlips(string s) {
    int n = s.length();
    int open = 0;  // Count of unmatched '('
    int close = 0; // Count of unmatched ')'
    
    // First pass: count unmatched closing brackets
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;  // Match with previous '('
            } else {
                close++; // Unmatched ')'
            }
        }
    }
    
    // After first pass:
    // - 'close' contains number of unmatched ')'
    // - 'open' contains number of unmatched '('
    
    // To make valid sequence:
    // - Need to flip half of unmatched ')' to '('
    // - Need to flip half of unmatched '(' to ')'
    // Total flips = ceil(close/2) + ceil(open/2)
    
    return (close + 1) / 2 + (open + 1) / 2;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        cout << minFlips(s) << endl;
    }
    
    return 0;
} 