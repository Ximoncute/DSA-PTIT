#include <iostream>
#include <queue>
#include <string>
using namespace std;

void printBinary(int n) {
    queue<string> q;
    q.push("1");
    
    for (int i = 1; i <= n; i++) {
        string current = q.front();
        q.pop();
        
        cout << current;
        if (i < n) cout << " ";
        
        // Thêm các số tiếp theo vào queue
        q.push(current + "0");
        q.push(current + "1");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        printBinary(n);
    }
    
    return 0;
} 