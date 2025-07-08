#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Cấu trúc node cho cây biểu thức
struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char c) {
        data = c;
        left = right = nullptr;
    }
};

// Kiểm tra ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Xây dựng cây biểu thức từ biểu thức hậu tố
Node* buildExpressionTree(string postfix) {
    stack<Node*> st;
    
    for (char c : postfix) {
        if (isOperator(c)) {
            // Tạo node mới cho toán tử
            Node* node = new Node(c);
            
            // Lấy hai toán hạng từ stack
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
            
            // Đưa node mới vào stack
            st.push(node);
        } else {
            // Tạo node lá cho toán hạng
            Node* node = new Node(c);
            st.push(node);
        }
    }
    
    return st.top();
}

// Duyệt cây theo thứ tự giữa để tạo biểu thức trung tố
string inorderTraversal(Node* root) {
    if (root == nullptr) return "";
    
    string result = "";
    
    // Nếu là node lá (toán hạng)
    if (root->left == nullptr && root->right == nullptr) {
        result += root->data;
    } else {
        // Nếu là node trung gian (toán tử)
        // Thêm dấu ngoặc trái nếu cần
        bool needParentheses = (root->left != nullptr && root->left->left != nullptr);
        if (needParentheses) result += "(";
        
        // Duyệt cây con trái
        result += inorderTraversal(root->left);
        
        // Thêm dấu ngoặc phải nếu cần
        if (needParentheses) result += ")";
        
        // Thêm khoảng trắng, toán tử, khoảng trắng
        result += " ";
        result += root->data;
        result += " ";
        
        // Thêm dấu ngoặc trái cho cây con phải nếu cần
        needParentheses = (root->right != nullptr && root->right->left != nullptr);
        if (needParentheses) result += "(";
        
        // Duyệt cây con phải
        result += inorderTraversal(root->right);
        
        // Thêm dấu ngoặc phải nếu cần
        if (needParentheses) result += ")";
    }
    
    return result;
}

// Phiên bản đơn giản hơn - không cần dấu ngoặc phức tạp
string simpleInorderTraversal(Node* root) {
    if (root == nullptr) return "";
    
    string result = "";
    
    // Nếu là node lá
    if (root->left == nullptr && root->right == nullptr) {
        return string(1, root->data);
    }
    
    // Duyệt cây con trái
    result += simpleInorderTraversal(root->left);
    
    // Thêm toán tử
    result += " " + string(1, root->data) + " ";
    
    // Duyệt cây con phải
    result += simpleInorderTraversal(root->right);
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string postfix;
        cin >> postfix;
        
        // Xây dựng cây biểu thức
        Node* root = buildExpressionTree(postfix);
        
        // Tạo biểu thức trung tố
        string infix = simpleInorderTraversal(root);
        
        cout << infix << endl;
    }
    
    return 0;
} 