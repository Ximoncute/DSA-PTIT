#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Xây dựng BST từ preorder
Node* buildBST(vector<int>& preorder, int& index, int minVal, int maxVal) {
    if (index >= preorder.size()) return nullptr;
    
    int val = preorder[index];
    
    // Kiểm tra xem giá trị có nằm trong khoảng hợp lệ không
    if (val < minVal || val > maxVal) return nullptr;
    
    index++;
    Node* root = new Node(val);
    
    // Xây dựng cây con trái (giá trị < root)
    root->left = buildBST(preorder, index, minVal, val);
    
    // Xây dựng cây con phải (giá trị > root)
    root->right = buildBST(preorder, index, val, maxVal);
    
    return root;
}

// Tính độ sâu của cây
int getDepth(Node* root) {
    if (!root) return 0;
    
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    
    return 1 + max(leftDepth, rightDepth);
}

// Giải phóng bộ nhớ
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> preorder(N);
        for (int i = 0; i < N; i++) {
            cin >> preorder[i];
        }
        
        // Xây dựng BST từ preorder
        int index = 0;
        Node* root = buildBST(preorder, index, INT_MIN, INT_MAX);
        
        // Tính độ sâu của cây
        int depth = getDepth(root);
        
        // Độ sâu của cây = chiều cao - 1 (nếu tính từ 0)
        // Hoặc có thể là chiều cao (nếu tính từ 1)
        // Theo ví dụ, có vẻ như tính từ 0
        cout << depth - 1 << endl;
        
        // Giải phóng bộ nhớ
        deleteTree(root);
    }
    
    return 0;
} 