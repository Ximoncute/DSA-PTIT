#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int x) {
    int left = 0, right = a.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (a[mid] == x) {
            return mid + 1; // Trả về vị trí 1-indexed
        }
        
        // Kiểm tra nửa trái có sắp xếp không
        if (a[left] <= a[mid]) {
            // Nửa trái được sắp xếp
            if (x >= a[left] && x < a[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Nửa phải được sắp xếp
            if (x > a[mid] && x <= a[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1; // Không tìm thấy
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int result = search(a, x);
        cout << result << endl;
    }
    return 0;
} 