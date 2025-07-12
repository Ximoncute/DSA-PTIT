#include <iostream>
using namespace std;

int min_of_three(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int nthUglyNumber(int n) {
    if (n <= 0) return 0;
    
    int ugly[10001]; // Since N <= 10^4
    ugly[1] = 1; // First ugly number is 1
    
    int i2 = 1, i3 = 1, i5 = 1; // Pointers for multiples of 2, 3, 5
    
    for (int i = 2; i <= n; i++) {
        // Calculate next candidates
        int next_multiple_of_2 = ugly[i2] * 2;
        int next_multiple_of_3 = ugly[i3] * 3;
        int next_multiple_of_5 = ugly[i5] * 5;
        
        // Choose the minimum
        int next_ugly = min_of_three(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
        ugly[i] = next_ugly;
        
        // Move the pointers
        if (next_ugly == next_multiple_of_2) i2++;
        if (next_ugly == next_multiple_of_3) i3++;
        if (next_ugly == next_multiple_of_5) i5++;
    }
    
    return ugly[n];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int result = nthUglyNumber(N);
        cout << result << endl;
    }
    
    return 0;
} 