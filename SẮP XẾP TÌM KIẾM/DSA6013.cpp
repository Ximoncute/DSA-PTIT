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
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        
        // Đọc mảng
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Tìm vị trí đầu tiên của x
        int first = lower_bound(a.begin(), a.end(), x) - a.begin();
        
        // Tìm vị trí sau phần tử cuối cùng của x
        int last = upper_bound(a.begin(), a.end(), x) - a.begin();
        
        // Kiểm tra xem x có tồn tại trong mảng không
        if (first == n || a[first] != x) {
            cout << -1 << endl;
        } else {
            // Số lần xuất hiện = last - first
            cout << last - first << endl;
        }
    }
    
    return 0;
} 