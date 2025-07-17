#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

long long largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    long long maxArea = 0;
    
    for (int i = 0; i <= n; i++) {
        // Use 0 as sentinel value for the last iteration
        int currentHeight = (i == n) ? 0 : heights[i];
        
        // While stack is not empty and current height is less than stack top
        while (!st.empty() && currentHeight < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            
            // Calculate width
            int width = st.empty() ? i : i - st.top() - 1;
            
            // Calculate area and update maximum
            long long area = (long long)height * width;
            maxArea = max(maxArea, area);
        }
        
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        
        cout << largestRectangleArea(heights) << endl;
    }
    
    return 0;
} 