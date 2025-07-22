#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Chèn node vào BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

// Duyệt preorder
void preorder(Node* root) {
    if (!root) return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
        
        Node* root = nullptr;
        
        // Đọc level-order và xây dựng BST
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            root = insert(root, val);
        }
        
        // In preorder
        preorder(root);
        cout << endl;
        
        // Giải phóng bộ nhớ
        deleteTree(root);
    }
    
    return 0;
} 