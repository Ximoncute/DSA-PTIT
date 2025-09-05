#include <iostream>
#include <string>
using namespace std;

string findCharAtPosition(int N, long long i) {
    // Precompute Fibonacci string lengths
    long long fibLen[93];
    fibLen[1] = 1; // "A"
    fibLen[2] = 1; // "B"
    
    for (int n = 3; n < 93; n++) {
        fibLen[n] = fibLen[n-1] + fibLen[n-2];
    }
    
    // Find the character using recursive approach
    while (N > 2) {
        if (i <= fibLen[N-2]) {
            N -= 2;
        } else {
            i -= fibLen[N-2];
            N -= 1;
        }
    }
    
    return (N == 1) ? "A" : "B";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        long long i;
        cin >> N >> i;
        
        cout << findCharAtPosition(N, i) << endl;
    }
    
    return 0;
}
