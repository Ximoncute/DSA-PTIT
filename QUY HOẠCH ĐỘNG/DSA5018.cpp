#include <iostream>
#include <string>
using namespace std;

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

// Function to expand around center and return length of palindrome
int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

int longestPalindrome(string s) {
    if (s.empty()) return 0;
    
    int maxLen = 0;
    
    for (int i = 0; i < s.length(); i++) {
        // Check for odd length palindromes (center at i)
        int len1 = expandAroundCenter(s, i, i);
        
        // Check for even length palindromes (center between i and i+1)
        int len2 = expandAroundCenter(s, i, i + 1);
        
        int currentMax = max_of_two(len1, len2);
        maxLen = max_of_two(maxLen, currentMax);
    }
    
    return maxLen;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
        
        int result = longestPalindrome(S);
        cout << result << endl;
    }
    
    return 0;
} 