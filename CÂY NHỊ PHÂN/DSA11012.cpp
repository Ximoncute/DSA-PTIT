#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Tìm node gốc của cây
Node* findRoot(map<int, Node*>& nodes, set<int>& children) {
    for (auto& p : nodes) {
        if (children.find(p.first) == children.end()) {
            return p.second;
        }
    }
    return nullptr;
}

// Xây dựng cây từ input
Node* buildTree(int N) {
    if (N == 0) return nullptr;
    
    map<int, Node*> nodes;
    set<int> children;
    
    for (int i = 0; i < N; i++) {
        int u, v;
        char x;
        cin >> u >> v >> x;
        
        // Tạo node nếu chưa tồn tại
        if (nodes.find(u) == nodes.end()) {
            nodes[u] = new Node(u);
        }
        if (nodes.find(v) == nodes.end()) {
            nodes[v] = new Node(v);
        }
        
        // Gắn node con vào node cha
        if (x == 'L') {
            nodes[u]->left = nodes[v];
        } else {
            nodes[u]->right = nodes[v];
        }
        
        children.insert(v);
    }
    
    return findRoot(nodes, children);
}

// So sánh hai cây nhị phân
bool isIdentical(Node* root1, Node* root2) {
    // Nếu cả hai đều null
    if (!root1 && !root2) return true;
    
    // Nếu một trong hai null
    if (!root1 || !root2) return false;
    
    // Kiểm tra giá trị và đệ quy cho cây con
    return (root1->data == root2->data) && 
           isIdentical(root1->left, root2->left) && 
           isIdentical(root1->right, root2->right);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N1, N2;
        cin >> N1;
        Node* tree1 = buildTree(N1);
        
        cin >> N2;
        Node* tree2 = buildTree(N2);
        
        // So sánh hai cây
        if (isIdentical(tree1, tree2)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
} 