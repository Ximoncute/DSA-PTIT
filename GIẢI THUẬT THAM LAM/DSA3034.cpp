#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> a(n), b(m), c(k);
        
        // Đọc dãy A
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Đọc dãy B
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        // Đọc dãy C
        for (int i = 0; i < k; i++) {
            cin >> c[i];
        }
        
        vector<int> result;
        int i = 0, j = 0, l = 0;
        
        // Sử dụng kỹ thuật 3 con trỏ để tìm phần tử chung
        while (i < n && j < m && l < k) {
            // Nếu 3 phần tử bằng nhau
            if (a[i] == b[j] && b[j] == c[l]) {
                result.push_back(a[i]);
                i++;
                j++;
                l++;
            }
            // Nếu a[i] nhỏ nhất, tăng i
            else if (a[i] < b[j]) {
                i++;
            }
            // Nếu b[j] nhỏ nhất, tăng j
            else if (b[j] < c[l]) {
                j++;
            }
            // Nếu c[l] nhỏ nhất, tăng l
            else {
                l++;
            }
        }
        
        // In kết quả
        if (result.empty()) {
            cout << "NO" << endl;
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i > 0) cout << " ";
                cout << result[i];
            }
            cout << endl;
        }
    }
    
    return 0;
} 