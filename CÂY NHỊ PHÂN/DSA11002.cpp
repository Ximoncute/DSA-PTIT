#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Cấu trúc node cho cây biểu thức
struct Node {
    string data;
    Node* left;
    Node* right;
    
    Node(string val) {
        data = val;
        left = right = nullptr;
    }
};

// Kiểm tra chuỗi có phải là toán tử hay không
bool isOperator(string s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

// Chuyển chuỗi thành số nguyên
int stringToInt(string s) {
    return stoi(s);
}

// Tính toán phép toán
int calculate(int left, string op, int right) {
    if (op == "+") return left + right;
    if (op == "-") return left - right;
    if (op == "*") return left * right;
    if (op == "/") return left / right;
    return 0;
}

// Xây dựng cây từ mảng level order
Node* buildTree(vector<string>& nodes, int index) {
    if (index >= nodes.size()) return nullptr;
    
    Node* root = new Node(nodes[index]);
    
    // Chỉ tạo node con nếu node hiện tại là toán tử
    if (isOperator(nodes[index])) {
        root->left = buildTree(nodes, 2 * index + 1);
        root->right = buildTree(nodes, 2 * index + 2);
    }
    
    return root;
}

// Tính giá trị của cây biểu thức
int evaluateTree(Node* root) {
    if (root == nullptr) return 0;
    
    // Nếu là node lá (toán hạng)
    if (root->left == nullptr && root->right == nullptr) {
        return stringToInt(root->data);
    }
    
    // Nếu là node trung gian (toán tử)
    int leftValue = evaluateTree(root->left);
    int rightValue = evaluateTree(root->right);
    
    return calculate(leftValue, root->data, rightValue);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        cin.ignore(); // Bỏ qua ký tự newline sau số n
        
        string line;
        getline(cin, line);
        
        // Tách các node từ chuỗi input
        vector<string> nodes;
        stringstream ss(line);
        string token;
        
        while (ss >> token) {
            nodes.push_back(token);
        }
        
        // Xây dựng cây từ level order
        Node* root = buildTree(nodes, 0);
        
        // Tính giá trị của cây
        int result = evaluateTree(root);
        
        cout << result << endl;
    }
    
    return 0;
} 