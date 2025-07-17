#include <bits/stdc++.h>
using namespace std;

// Hàm tìm hình chữ nhật lớn nhất trong histogram
int largestRectangleInHistogram(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> matrix(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        
        // Tạo histogram cho mỗi dòng
        vector<int> heights(m, 0);
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            // Cập nhật histogram cho dòng hiện tại
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Tìm hình chữ nhật lớn nhất trong histogram hiện tại
            int area = largestRectangleInHistogram(heights);
            maxArea = max(maxArea, area);
        }
        
        cout << maxArea << "\n";
    }
    
    return 0;
} 