#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Hàm thêm node con vào cây
void insert(Node* &root, int u, int v, char c, map<int, Node*> &nodeMap) {
    if (!nodeMap[u]) {
        nodeMap[u] = new Node(u);
        if (!root) root = nodeMap[u];
    }
    Node* parent = nodeMap[u];
    Node* child = new Node(v);
    nodeMap[v] = child;

    if (c == 'L') parent->left = child;
    else parent->right = child;
}

// Duyệt cây để tính tổng lá bên phải
int sumRightLeaves(Node* root) {
    if (!root) return 0;
    int sum = 0;
    if (root->right && !root->right->left && !root->right->right)
        sum += root->right->data;
    return sum + sumRightLeaves(root->left) + sumRightLeaves(root->right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        Node* root = nullptr;
        map<int, Node*> nodeMap;
        for (int i = 0; i < N; ++i) {
            int u, v; char c;
            cin >> u >> v >> c;
            insert(root, u, v, c, nodeMap);
        }
        cout << sumRightLeaves(root) << '\n';
    }
    return 0;
}
