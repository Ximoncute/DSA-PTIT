#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string expr;
        getline(cin, expr);
        stack<int> st;
        vector<int> res(expr.size(), 0);
        int cnt = 1;
        for (size_t i = 0; i < expr.size(); ++i) {
            if (expr[i] == '(') {
                st.push(cnt);
                res[i] = cnt;
                cnt++;
            } else if (expr[i] == ')') {
                if (!st.empty()) {
                    res[i] = st.top();
                    st.pop();
                }
            }
        }
        for (size_t i = 0; i < expr.size(); ++i) {
            if (expr[i] == '(' || expr[i] == ')') {
                cout << res[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}