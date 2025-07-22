#include<iostream>
#include<map>
#include<set>
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
    return -1;
}

// Kiểm tra tất cả node lá có cùng mức hay không
bool checkLeavesAtSameLevel(Node* root, int currentLevel, int& leafLevel) {
    if (root == nullptr) return true;
    
    // Nếu là node lá
    if (root->left == nullptr && root->right == nullptr) {
        // Nếu chưa gặp node lá nào trước đó
        if (leafLevel == -1) {
            leafLevel = currentLevel;
            return true;
        }
        // Kiểm tra mức của node lá hiện tại với mức đã lưu
        return leafLevel == currentLevel;
    }
    
    // Kiểm tra đệ quy cho cây con trái và phải
    bool leftResult = checkLeavesAtSameLevel(root->left, currentLevel + 1, leafLevel);
    bool rightResult = checkLeavesAtSameLevel(root->right, currentLevel + 1, leafLevel);
    
    return leftResult && rightResult;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        map<int, Node*> nodes;
        set<int> children;
        
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
        
        // Tìm root
        int rootValue = findRoot(nodes, children);
        
        if (rootValue != -1) {
            int leafLevel = -1;
            bool result = checkLeavesAtSameLevel(nodes[rootValue], 0, leafLevel);
            cout << (result ? 1 : 0) << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
} 