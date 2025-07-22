#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Tìm root của cây (node không phải con của node nào khác)
int findRoot(map<int, Node*>& nodes, set<int>& children) {
    for (auto& pair : nodes) {
        if (children.find(pair.first) == children.end()) {
            return pair.first;
        }
    }
    return -1; // Không tìm thấy root
}

// Duyệt cây theo level-order sử dụng BFS
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    
    bool first = true;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        if (!first) cout << " ";
        cout << current->data;
        first = false;
        
        // Thêm con trái trước, sau đó con phải
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        map<int, Node*> nodes; // Lưu trữ các node
        set<int> children; // Tập hợp các node con
        
        for (int i = 0; i < n; i++) {
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
            
            // Gán con cho node cha
            if (x == 'L') {
                nodes[u]->left = nodes[v];
            } else {
                nodes[u]->right = nodes[v];
            }
            
            // Đánh dấu v là node con
            children.insert(v);
        }
        
        // Tìm root (node không phải con của node nào)
        int rootValue = findRoot(nodes, children);
        
        if (rootValue != -1) {
            levelOrderTraversal(nodes[rootValue]);
        }
        
        cout << endl;
    }
    
    return 0;
} 