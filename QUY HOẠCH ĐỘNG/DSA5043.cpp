#include <iostream>
using namespace std;

int stringLength(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

bool isPalindrome(char s[], int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int longestPalindromeSubstring(char s[]) {
    int n = stringLength(s);
    if (n <= 1) return n;
    
    int maxLength = 1;
    
    // Duyệt qua tất cả các đoạn con có thể
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Kiểm tra đoạn con từ i đến j
            if (isPalindrome(s, i, j)) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }
            }
        }
    }
    
    return maxLength;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        char N[1001];
        cin >> N;
        
        int result = longestPalindromeSubstring(N);
        cout << result << endl;
    }
    
    return 0;
} 