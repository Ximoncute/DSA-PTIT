#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        
        stack<int> st;
        int result = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else { // s[i] == ')'
                if(!st.empty()) {
                    st.pop();
                    result += 2; // Mỗi cặp ngoặc hợp lệ có độ dài 2
                }
            }
        }
        
        cout << result << endl;
    }
    return 0;
} 