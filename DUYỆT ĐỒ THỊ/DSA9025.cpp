#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        
        // Khởi tạo local variables
        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);
        vector<int> parent(V + 1, -1);
        
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
        
        // Tìm đường đi từ s đến t bằng DFS iterative
        stack<int> st;
        st.push(s);
        bool found = false;
        
        while(!st.empty() && !found) {
            int u = st.top();
            st.pop();
            
            if(!visited[u]) {
                visited[u] = true;
                
                if(u == t) {
                    found = true;
                    break;
                }
                
                // Thêm các đỉnh kề vào stack theo thứ tự ngược
                for(int i = adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if(!visited[v]) {
                        parent[v] = u;
                        st.push(v);
                    }
                }
            }
        }
        
        // Tái tạo và in đường đi
        if(found) {
            vector<int> path;
            int current = t;
            
            while(current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            
            reverse(path.begin(), path.end());
            
            for(int i = 0; i < path.size(); i++) {
                cout << path[i];
                if(i < path.size() - 1) cout << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    
    return 0;
} 