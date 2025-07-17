#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    stack<int> st;
    
    for (int i = 0; i < Q; i++) {
        string query;
        cin >> query;
        
        if (query == "PUSH") {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (query == "POP") {
            if (!st.empty()) {
                st.pop();
            }
        }
        else if (query == "PRINT") {
            if (st.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << st.top() << endl;
            }
        }
    }
    
    return 0;
} 