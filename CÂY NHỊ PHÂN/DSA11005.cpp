#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
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

// Hàm xây dựng cây từ Inorder và Level-order
Node* buildTree(vector<int>& inorder, vector<int>& levelorder) {
    if (inorder.empty() || levelorder.empty()) return nullptr;
    
    // Tạo map để tra cứu nhanh vị trí trong inorder
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    
    // Root là phần tử đầu tiên trong level-order
    Node* root = new Node(levelorder[0]);
    
    // Sử dụng queue để xây dựng cây theo level-order
    queue<pair<Node*, pair<int, int>>> q;
    
    // Tìm vị trí root trong inorder
    int rootPos = inorderMap[levelorder[0]];
    q.push({root, {0, (int)inorder.size() - 1}});
    
    int levelIndex = 1;
    
    while (!q.empty() && levelIndex < levelorder.size()) {
        auto current = q.front();
        q.pop();
        
        Node* node = current.first;
        int inStart = current.second.first;
        int inEnd = current.second.second;
        
        // Tìm vị trí của node hiện tại trong inorder
        int nodePos = inorderMap[node->data];
        
        // Tìm con trái và con phải từ level-order
        Node* leftChild = nullptr;
        Node* rightChild = nullptr;
        
        // Duyệt level-order để tìm con trái và con phải
        for (int i = levelIndex; i < levelorder.size(); i++) {
            int val = levelorder[i];
            int pos = inorderMap[val];
            
            // Nếu nằm bên trái của node hiện tại
            if (pos < nodePos && pos >= inStart && pos <= inEnd) {
                if (leftChild == nullptr) {
                    leftChild = new Node(val);
                    node->left = leftChild;
                    // Hoán đổi để đưa lên đầu
                    swap(levelorder[i], levelorder[levelIndex]);
                    levelIndex++;
                    break;
                }
            }
        }
        
        for (int i = levelIndex; i < levelorder.size(); i++) {
            int val = levelorder[i];
            int pos = inorderMap[val];
            
            // Nếu nằm bên phải của node hiện tại
            if (pos > nodePos && pos >= inStart && pos <= inEnd) {
                if (rightChild == nullptr) {
                    rightChild = new Node(val);
                    node->right = rightChild;
                    // Hoán đổi để đưa lên đầu
                    swap(levelorder[i], levelorder[levelIndex]);
                    levelIndex++;
                    break;
                }
            }
        }
        
        // Thêm con trái vào queue
        if (leftChild) {
            q.push({leftChild, {inStart, nodePos - 1}});
        }
        
        // Thêm con phải vào queue  
        if (rightChild) {
            q.push({rightChild, {nodePos + 1, inEnd}});
        }
    }
    
    return root;
}

// Duyệt cây theo postorder
void postorderTraversal(Node* root, vector<int>& result) {
    if (root == nullptr) return;
    
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->data);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> inorder(n);
        vector<int> levelorder(n);
        
        // Đọc inorder
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }
        
        // Đọc level-order
        for (int i = 0; i < n; i++) {
            cin >> levelorder[i];
        }
        
        // Xây dựng cây
        Node* root = buildTree(inorder, levelorder);
        
        // Duyệt postorder
        vector<int> postorder;
        postorderTraversal(root, postorder);
        
        // In kết quả
        for (int i = 0; i < postorder.size(); i++) {
            cout << postorder[i];
            if (i < postorder.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 