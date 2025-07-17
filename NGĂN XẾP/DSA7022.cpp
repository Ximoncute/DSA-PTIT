#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Đếm tần suất xuất hiện của mỗi phần tử
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
        }
        
        // Tạo mảng tần suất tương ứng với mỗi vị trí
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            f[i] = freq[a[i]];
        }
        
        // Tìm phần tử gần nhất phía bên phải có tần suất lớn hơn
        vector<int> result(n, -1);
        stack<int> st; // Stack lưu chỉ số
        
        for (int i = 0; i < n; i++) {
            // Trong khi stack không rỗng và tần suất hiện tại lớn hơn tần suất của phần tử ở đỉnh stack
            while (!st.empty() && f[i] > f[st.top()]) {
                result[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        
        // In kết quả
        for (int i = 0; i < n; i++) {
            cout << result[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
} 