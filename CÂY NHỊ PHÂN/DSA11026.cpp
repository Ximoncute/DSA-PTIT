#include <bits/stdc++.h>
using namespace std;

// Xây dựng BST cân bằng và in postorder
void buildBalancedBST(vector<int>& arr, int left, int right, vector<int>& postorder) {
    if (left > right) return;
    
    // Chọn phần tử giữa làm root
    int mid = (left + right) / 2;
    
    // Đệ quy xây dựng cây con trái
    buildBalancedBST(arr, left, mid - 1, postorder);
    
    // Đệ quy xây dựng cây con phải
    buildBalancedBST(arr, mid + 1, right, postorder);
    
    // Thêm root vào postorder (sau khi duyệt con trái và con phải)
    postorder.push_back(arr[mid]);
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
        
        // Xây dựng BST cân bằng và lấy postorder
        vector<int> postorder;
        buildBalancedBST(arr, 0, N - 1, postorder);
        
        // In kết quả
        for (int i = 0; i < postorder.size(); i++) {
            cout << postorder[i];
            if (i < postorder.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 