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

// Kiểm tra xem cây có phải là cây đủ không
bool isFullTree(Node* root) {
    if (!root) return true;
    
    // Nếu là node lá (không có con nào)
    if (!root->left && !root->right) {
        return true;
    }
    
    // Nếu node có đủ 2 con, kiểm tra đệ quy
    if (root->left && root->right) {
        return isFullTree(root->left) && isFullTree(root->right);
    }
    
    // Nếu chỉ có 1 con thì không phải cây đủ
    return false;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        if (N == 0) {
            cout << "1" << endl;
            continue;
        }
        
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
        
        // Tìm node gốc
        Node* root = findRoot(nodes, children);
        
        // Kiểm tra cây đủ
        if (isFullTree(root)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
        
        // Giải phóng bộ nhớ
        for (auto& p : nodes) {
            delete p.second;
        }
    }
    
    return 0;
} 