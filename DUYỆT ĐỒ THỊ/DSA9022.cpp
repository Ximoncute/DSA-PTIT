#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int V, E, start;
        cin >> V >> E >> start;
        
        // Khởi tạo local variables
        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);
        vector<int> result;
        
        // Đọc các cạnh
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if(u >= 1 && u <= V && v >= 1 && v <= V) {
                adj[u].push_back(v);
            }
        }
        
        // Sắp xếp các danh sách kề
        for(int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        // Thực hiện DFS iterative
        stack<int> st;
        st.push(start);
        
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            
            if(!visited[u]) {
                visited[u] = true;
                result.push_back(u);
                
                // Thêm các đỉnh kề vào stack theo thứ tự ngược
                for(int i = adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if(!visited[v]) {
                        st.push(v);
                    }
                }
            }
        }
        
        // In kết quả
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 