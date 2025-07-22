#include <bits/stdc++.h>
using namespace std;

// Xây dựng BST cân bằng và in preorder
void buildBalancedBST(vector<int>& arr, int left, int right, vector<int>& preorder) {
    if (left > right) return;
    
    // Chọn phần tử giữa làm root
    int mid = (left + right) / 2;
    
    // Thêm root vào preorder
    preorder.push_back(arr[mid]);
    
    // Đệ quy xây dựng cây con trái
    buildBalancedBST(arr, left, mid - 1, preorder);
    
    // Đệ quy xây dựng cây con phải
    buildBalancedBST(arr, mid + 1, right, preorder);
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
        
        // Xây dựng BST cân bằng và lấy preorder
        vector<int> preorder;
        buildBalancedBST(arr, 0, N - 1, preorder);
        
        // In kết quả
        for (int i = 0; i < preorder.size(); i++) {
            cout << preorder[i];
            if (i < preorder.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 