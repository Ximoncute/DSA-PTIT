#include <bits/stdc++.h>
using namespace std;

// Hàm để chuẩn hóa biểu thức thành dạng tổng các hạng tử với dấu
map<char, int> normalize(string expr) {
    map<char, int> result;
    stack<int> signs; // Stack để lưu dấu
    signs.push(1); // Dấu ban đầu là dương
    
    int current_sign = 1;
    
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        if (c == '(') {
            signs.push(current_sign * signs.top());
        }
        else if (c == ')') {
            signs.pop();
        }
        else if (c == '+') {
            current_sign = 1;
        }
        else if (c == '-') {
            current_sign = -1;
        }
        else if (c >= 'a' && c <= 'z') {
            // Đây là một biến
            int final_sign = current_sign * signs.top();
            result[c] += final_sign;
            current_sign = 1; // Reset về dấu dương cho lần tiếp theo
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    cin.ignore(); // Bỏ qua ký tự newline sau số t
    
    while (t--) {
        string p1, p2;
        getline(cin, p1);
        getline(cin, p2);
        
        map<char, int> norm1 = normalize(p1);
        map<char, int> norm2 = normalize(p2);
        
        if (norm1 == norm2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 