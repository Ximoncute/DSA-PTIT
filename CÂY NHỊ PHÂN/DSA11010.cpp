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

// Tính chiều cao của cây
int getHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// Kiểm tra xem cây có phải là cây hoàn hảo không
bool isPerfectTree(Node* root, int depth, int level) {
    if (!root) return true;
    
    // Nếu là node lá, kiểm tra xem có ở đúng mức cuối không
    if (!root->left && !root->right) {
        return level == depth;
    }
    
    // Nếu chỉ có 1 con thì không phải cây hoàn hảo
    if (!root->left || !root->right) {
        return false;
    }
    
    // Kiểm tra đệ quy cho cả 2 con
    return isPerfectTree(root->left, depth, level + 1) && 
           isPerfectTree(root->right, depth, level + 1);
}

bool checkPerfectTree(Node* root) {
    if (!root) return true;
    
    int height = getHeight(root);
    return isPerfectTree(root, height, 1);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        if (N == 0) {
            cout << "Yes" << endl;
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
        
        // Kiểm tra cây hoàn hảo
        if (checkPerfectTree(root)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        
        // Giải phóng bộ nhớ
        for (auto& p : nodes) {
            delete p.second;
        }
    }
    
    return 0;
} 