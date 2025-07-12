#include <iostream>
using namespace std;

int string_length(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

long long sumOfSubstrings(char s[]) {
    int n = string_length(s);
    long long result = 0;
    
    // For each starting position i
    for (int i = 0; i < n; i++) {
        // For each ending position j >= i
        for (int j = i; j < n; j++) {
            // Calculate the value of substring s[i...j]
            long long value = 0;
            for (int k = i; k <= j; k++) {
                value = value * 10 + (s[k] - '0');
            }
            result += value;
        }
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        char N[20];
        cin >> N;
        
        long long result = sumOfSubstrings(N);
        cout << result << endl;
    }
    
    return 0;
} 