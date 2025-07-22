#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int preIndex = 0;

Node* buildTree(vector<int>& inorder, vector<int>& preorder, int start, int end) {
    if (start > end) return NULL;
    
    Node* root = new Node(preorder[preIndex++]);
    
    if (start == end) return root;
    
    // Tìm vị trí của root trong inorder
    int rootIndex = -1;
    for (int i = start; i <= end; i++) {
        if (inorder[i] == root->data) {
            rootIndex = i;
            break;
        }
    }
    
    // Xây dựng cây con trái trước, sau đó cây con phải
    root->left = buildTree(inorder, preorder, start, rootIndex - 1);
    root->right = buildTree(inorder, preorder, rootIndex + 1, end);
    
    return root;
}

void postOrder(Node* root) {
    if (root == NULL) return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> inorder(n), preorder(n);
        
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> preorder[i];
        }
        
        preIndex = 0; // Reset cho mỗi test case
        
        Node* root = buildTree(inorder, preorder, 0, n - 1);
        
        postOrder(root);
        cout << endl;
    }
    
    return 0;
} 