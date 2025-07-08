#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Đánh dấu vị trí thuộc palindrome độ dài >= 2
    vector<bool> good(n, false);
    
    // Palindrome độ dài 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            good[i] = good[i + 1] = true;
        }
    }
    
    // Palindrome độ dài 3
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i + 1]) {
            good[i - 1] = good[i] = good[i + 1] = true;
        }
    }
    
    // Palindrome độ dài 4
    for (int i = 0; i < n - 3; i++) {
        if (s[i] == s[i + 3] && s[i + 1] == s[i + 2]) {
            good[i] = good[i + 1] = good[i + 2] = good[i + 3] = true;
        }
    }
    
    // Palindrome độ dài 5
    for (int i = 2; i < n - 2; i++) {
        if (s[i - 2] == s[i + 2] && s[i - 1] == s[i + 1]) {
            for (int j = i - 2; j <= i + 2; j++) good[j] = true;
        }
    }
    
    long long count = 0;
    
    // Đếm xâu con tốt bằng O(n²) với early termination
    for (int i = 0; i < n; i++) {
        if (!good[i]) continue; // Nếu vị trí đầu không good thì skip
        
        for (int j = i; j < n; j++) {
            if (!good[j]) break; // Nếu gặp vị trí không good thì dừng
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
} 