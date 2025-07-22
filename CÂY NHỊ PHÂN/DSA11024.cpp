#include <bits/stdc++.h>
using namespace std;

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
        
        // Node gốc của BST cân bằng là phần tử ở giữa
        // Với mảng có N phần tử, phần tử giữa ở vị trí (N-1)/2
        int rootIndex = (N - 1) / 2;
        int root = arr[rootIndex];
        
        cout << root << endl;
    }
    
    return 0;
} 