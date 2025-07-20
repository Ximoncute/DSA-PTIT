#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int V, E;
        cin >> V >> E;
        
        // Khởi tạo danh sách kề
        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);
        
        // Đọc các cạnh (đồ thị vô hướng nên thêm cả 2 chiều)
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            // Kiểm tra bounds để tránh lỗi
            if(u >= 1 && u <= V && v >= 1 && v <= V) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        // Đếm số thành phần liên thông bằng DFS iterative
        int componentCount = 0;
        
        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                // Tìm thấy một thành phần liên thông mới
                // Sử dụng stack thay vì đệ quy để tránh stack overflow
                stack<int> st;
                st.push(i);
                visited[i] = true;
                
                while(!st.empty()) {
                    int u = st.top();
                    st.pop();
                    
                    for(int v : adj[u]) {
                        if(!visited[v]) {
                            visited[v] = true;
                            st.push(v);
                        }
                    }
                }
                
                componentCount++;
            }
        }
        
        cout << componentCount << endl;
    }
    
    return 0;
} 