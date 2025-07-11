#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n), b(n);
        
        // Đọc mảng A
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Đọc mảng B
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        // Sắp xếp mảng A tăng dần
        sort(a.begin(), a.end());
        
        // Sắp xếp mảng B giảm dần
        sort(b.begin(), b.end(), greater<long long>());
        
        // Tính tổng tích
        long long result = 0;
        for (int i = 0; i < n; i++) {
            result += a[i] * b[i];
        }
        
        cout << result << endl;
    }
    
    return 0;
} 