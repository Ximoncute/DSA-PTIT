#include <bits/stdc++.h>
using namespace std;

bool isInorderBST(vector<int>& arr) {
    int n = arr.size();
    
    // Kiểm tra xem mảng có tăng dần nghiêm ngặt không
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i-1]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        if (isInorderBST(arr)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
} 