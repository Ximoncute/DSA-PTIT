#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Sắp xếp mảng
        sort(a.begin(), a.end());
        
        long long count = 0;
        int j = 1;
        // Dùng two pointers tối ưu
        for (int i = 0; i < n - 1; i++) {
            // Đảm bảo j >= i + 1
            if (j <= i) j = i + 1;
            
            // Tìm vị trí đầu tiên mà a[j] >= a[i] + k
            while (j < n && a[j] - a[i] < k) {
                j++;
            }
            
            // Tất cả phần tử từ i+1 đến j-1 đều có hiệu < k với a[i]
            count += j - i - 1;
        }
        
        cout << count << endl;
    }
    return 0;
} 