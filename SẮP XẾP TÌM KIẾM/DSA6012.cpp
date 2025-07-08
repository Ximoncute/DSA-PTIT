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
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        
        // Đọc mảng
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Sắp xếp mảng theo thứ tự giảm dần
        sort(a.begin(), a.end(), greater<int>());
        
        // In ra k phần tử lớn nhất
        for (int i = 0; i < k; i++) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << endl;
    }
    
    return 0;
} 