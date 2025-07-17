#include <iostream>
#include <queue>
#include <string>
using namespace std;

int countBDN(long long n) {
    if (n <= 1) return 0;
    
    queue<long long> q;
    q.push(1);
    
    int count = 0;
    
    while (!q.empty()) {
        long long current = q.front();
        q.pop();
        
        if (current > n) {
            continue;
        }
        
        count++;
        
        // Sinh số tiếp theo bằng cách thêm '0' và '1'
        long long next0 = current * 10;
        long long next1 = current * 10 + 1;
        
        // Kiểm tra overflow và chỉ thêm nếu nhỏ hơn n
        if (next0 > 0 && next0 < n) {
            q.push(next0);
        }
        if (next1 > 0 && next1 < n) {
            q.push(next1);
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        long long N;
        cin >> N;
        cout << countBDN(N) << endl;
    }
    
    return 0;
} 