#include <iostream>
#include <string>
using namespace std;

string fibonacciString(int n) {
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
    
    return current;
}

int countAInPrefix(int n, int k) {
    string str = fibonacciString(n);
    int count = 0;
    for (int i = 0; i < k && i < str.length(); i++) {
        if (str[i] == 'A') count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << countAInPrefix(n, k) << endl;
    }
    return 0;
}
