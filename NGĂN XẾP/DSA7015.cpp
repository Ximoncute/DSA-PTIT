#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Hàm thực hiện phép toán
long long calculate(long long a, long long b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Hàm chuyển đổi trung tố sang hậu tố
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if (isdigit(c)) {
            // Đọc toàn bộ số
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' '; // Thêm dấu cách để phân tách số
            i--; // Lùi lại vì vòng lặp sẽ tăng i
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.pop(); // Bỏ dấu '('
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!st.empty() && st.top() != '(' && 
                   precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(c);
        }
    }
    
    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }
    
    return postfix;
}

// Hàm tính giá trị biểu thức hậu tố
long long evaluatePostfix(string postfix) {
    stack<long long> st;
    stringstream ss(postfix);
    string token;
    
    while (ss >> token) {
        if (isdigit(token[0])) {
            st.push(stoll(token));
        }
        else {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            st.push(calculate(a, b, token[0]));
        }
    }
    
    return st.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    cin.ignore(); // Bỏ qua ký tự newline
    
    while (t--) {
        string s;
        getline(cin, s);
        
        string postfix = infixToPostfix(s);
        long long result = evaluatePostfix(postfix);
        
        cout << result << "\n";
    }
    
    return 0;
} 