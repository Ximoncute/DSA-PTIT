#include <iostream>
#include <string>
using namespace std;

// Function to generate F[n] string
string generateFibString(int n) {
    if (n == 0) return "A";
    if (n == 1) return "B";
    
    string prev2 = "A";
    string prev1 = "B";
    string current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

// Function to count 'B' in first k positions more efficiently
int countBInFibString(int n, int k) {
    if (n == 0) {
        return (k >= 1 && "A"[0] == 'B') ? 1 : 0;
    }
    if (n == 1) {
        return (k >= 1 && "B"[0] == 'B') ? 1 : 0;
    }
    
    // Precompute lengths of F[i]
    long long len[50];
    len[0] = 1; // "A"
    len[1] = 1; // "B"
    
    for (int i = 2; i <= n; i++) {
        len[i] = len[i-1] + len[i-2];
    }
    
    // If k equals the full length, we can use the pattern
    if (k == len[n]) {
        // Count of 'B's follows Fibonacci pattern
        long long count[50];
        count[0] = 0; // "A" has 0 'B's
        count[1] = 1; // "B" has 1 'B'
        
        for (int i = 2; i <= n; i++) {
            count[i] = count[i-1] + count[i-2];
        }
        
        return count[n];
    }
    
    // For partial strings, we need to generate and count
    string str = generateFibString(n);
    int count = 0;
    for (int i = 0; i < k && i < str.length(); i++) {
        if (str[i] == 'B') {
            count++;
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        cout << countBInFibString(n, k) << endl;
    }
    
    return 0;
}
