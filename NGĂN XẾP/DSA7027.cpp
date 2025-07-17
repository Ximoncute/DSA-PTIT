#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stack to store indices
    
    // Process elements from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from stack while they are smaller than or equal to current element
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        
        // If stack is not empty, top element is the next greater element
        if (!st.empty()) {
            result[i] = arr[st.top()];
        }
        
        // Push current element's index to stack
        st.push(i);
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int> result = nextGreaterElement(arr);
        
        for (int i = 0; i < n; i++) {
            cout << result[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 