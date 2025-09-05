#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* buildBST(const vector<int>& pre, int& idx, int minVal, int maxVal) {
    if (idx >= pre.size() || pre[idx] < minVal || pre[idx] > maxVal) return nullptr;
    int val = pre[idx++];
    Node* root = new Node(val);
    root->left = buildBST(pre, idx, minVal, val - 1);
    root->right = buildBST(pre, idx, val + 1, maxVal);
    return root;
}

void postorder(Node* root, vector<int>& res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> pre(N);
        for (int i = 0; i < N; ++i) cin >> pre[i];
        int idx = 0;
        Node* root = buildBST(pre, idx, INT_MIN, INT_MAX);
        vector<int> res;
        postorder(root, res);
        for (size_t i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i + 1 < res.size()) cout << " ";
        }
        cout << endl;
    }
    return 0;
}