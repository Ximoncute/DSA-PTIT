#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Bỏ qua newline sau số test
    
    while(t--) {
        string s;
        getline(cin, s);
        
        stack<int> st; // Stack lưu trữ dấu: 1 là +, -1 là -
        st.push(1); // Dấu ban đầu là +
        
        string result = "";
        
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if(c == '+') {
                result += (st.top() == 1) ? "+" : "-";
            }
            else if(c == '-') {
                result += (st.top() == 1) ? "-" : "+";
            }
            else if(c == '(') {
                // Lấy dấu trước dấu ngoặc mở
                if(i > 0 && s[i-1] == '-') {
                    st.push(-st.top()); // Đảo dấu
                } else {
                    st.push(st.top()); // Giữ nguyên dấu
                }
            }
            else if(c == ')') {
                st.pop();
            }
            else {
                result += c; // Thêm ký tự (toán hạng)
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
} 