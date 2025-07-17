#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st; // Stack to store indices
    
    for (int i = 0; i < n; i++) {
        // Pop elements from stack while they are smaller than or equal to current price
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }
        
        // If stack is empty, span is i+1 (all previous days)
        // Otherwise, span is i - index of previous greater element
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }
        
        // Push current index to stack
        st.push(i);
    }
    
    return span;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        
        vector<int> span = calculateSpan(prices);
        
        for (int i = 0; i < n; i++) {
            cout << span[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 