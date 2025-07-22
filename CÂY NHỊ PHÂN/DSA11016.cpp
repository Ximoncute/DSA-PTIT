#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Thêm node vào cây
void insert(Node* &root, int u, int v, char c, map<int, Node*> &nodeMap) {
    if (nodeMap.find(u) == nodeMap.end()) {
        nodeMap[u] = new Node(u);
        if (!root) root = nodeMap[u];
    }
    if (nodeMap.find(v) == nodeMap.end()) {
        nodeMap[v] = new Node(v);
    }
    
    if (c == 'L') {
        nodeMap[u]->left = nodeMap[v];
    } else {
        nodeMap[u]->right = nodeMap[v];
    }
}

// Tìm root
Node* findRoot(map<int, Node*> &nodeMap, set<int> &children) {
    for (auto& p : nodeMap) {
        if (children.find(p.first) == children.end()) {
            return p.second;
        }
    }
    return nullptr;
}

// Duyệt inorder để lấy danh sách giá trị
void inorderValues(Node* root, vector<int> &values) {
    if (!root) return;
    inorderValues(root->left, values);
    values.push_back(root->data);
    inorderValues(root->right, values);
}

// Duyệt inorder và gán giá trị mới
void inorderAssign(Node* root, vector<int> &sortedValues, int &index) {
    if (!root) return;
    inorderAssign(root->left, sortedValues, index);
    root->data = sortedValues[index++];
    inorderAssign(root->right, sortedValues, index);
}

// In kết quả inorder
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        map<int, Node*> nodeMap;
        set<int> children;
        Node* root = nullptr;
        
        for (int i = 0; i < N; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            
            children.insert(v);
            insert(root, u, v, c, nodeMap);
        }
        
        // Tìm root
        root = findRoot(nodeMap, children);
        
        // Lấy danh sách giá trị từ cây gốc
        vector<int> values;
        inorderValues(root, values);
        
        // Sắp xếp danh sách
        sort(values.begin(), values.end());
        
        // Gán lại giá trị cho cây để tạo BST
        int index = 0;
        inorderAssign(root, values, index);
        
        // In kết quả
        printInorder(root);
        cout << endl;
        
        // Giải phóng bộ nhớ
        for (auto& p : nodeMap) {
            delete p.second;
        }
    }
    
    return 0;
} 