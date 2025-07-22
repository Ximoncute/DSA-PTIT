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

// Tìm và in các node lá
void findLeaves(Node* root, vector<int>& leaves) {
    if (!root) return;
    
    // Nếu là node lá (không có con trái và con phải)
    if (!root->left && !root->right) {
        leaves.push_back(root->data);
        return;
    }
    
    // Đệ quy cho cây con trái và phải
    findLeaves(root->left, leaves);
    findLeaves(root->right, leaves);
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
        
        // Tìm các node lá
        vector<int> leaves;
        findLeaves(root, leaves);
        
        // In kết quả
        for (int i = 0; i < leaves.size(); i++) {
            cout << leaves[i];
            if (i < leaves.size() - 1) cout << " ";
        }
        cout << endl;
        
        // Giải phóng bộ nhớ
        deleteTree(root);
    }
    
    return 0;
} 