#include <bits/stdc++.h>
using namespace std;

// Đếm số node lá trong BST cân bằng
int countLeaves(vector<int>& arr, int left, int right) {
    if (left > right) return 0;
    
    // Nếu chỉ có 1 phần tử thì đó là node lá
    if (left == right) return 1;
    
    // Chọn phần tử giữa làm root
    int mid = (left + right) / 2;
    
    // Đếm node lá ở cây con trái và cây con phải
    int leftLeaves = countLeaves(arr, left, mid - 1);
    int rightLeaves = countLeaves(arr, mid + 1, right);
    
    return leftLeaves + rightLeaves;
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
        
        // Sắp xếp mảng để tạo BST cân bằng
        sort(arr.begin(), arr.end());
        
        // Đếm số node lá
        int leafCount = countLeaves(arr, 0, N - 1);
        
        cout << leafCount << endl;
    }
    
    return 0;
} 