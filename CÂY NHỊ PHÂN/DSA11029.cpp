#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> paths;

void dfs(int node, int parent, vector<int>& currentPath) {
    currentPath.push_back(node);
    
    // Kiểm tra xem node có phải là lá không
    bool isLeaf = true;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            isLeaf = false;
            dfs(neighbor, node, currentPath);
        }
    }
    
    // Nếu là node lá, lưu đường đi
    if (isLeaf) {
        paths.push_back(currentPath);
    }
    
    currentPath.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        // Khởi tạo danh sách kề
        adj.assign(N + 1, vector<int>());
        paths.clear();
        
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Sắp xếp danh sách kề để đảm bảo thứ tự
        for (int i = 1; i <= N; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        // DFS từ node gốc (node 1)
        vector<int> currentPath;
        dfs(1, -1, currentPath);
        
        // Sắp xếp các đường đi theo node lá
        sort(paths.begin(), paths.end(), [](const vector<int>& a, const vector<int>& b) {
            return a.back() < b.back();
        });
        
        // In kết quả
        for (const auto& path : paths) {
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}