#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> disc, low, parent;
    vector<bool> ap;
    int timer;
    
    void bridgeUtil(int u) {
        int children = 0;
        visited[u] = true;
        
        disc[u] = low[u] = ++timer;
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                bridgeUtil(v);
                
                low[u] = min(low[u], low[v]);
                
                // u là đỉnh trụ trong 2 trường hợp:
                // (1) u là gốc và có nhiều hơn 1 con
                if (parent[u] == -1 && children > 1)
                    ap[u] = true;
                    
                // (2) u không phải gốc và low[v] >= disc[u]
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V + 1);
        visited.resize(V + 1);
        disc.resize(V + 1);
        low.resize(V + 1);
        parent.resize(V + 1);
        ap.resize(V + 1);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> findArticulationPoints() {
        // Khởi tạo
        fill(visited.begin(), visited.end(), false);
        fill(disc.begin(), disc.end(), -1);
        fill(low.begin(), low.end(), -1);
        fill(parent.begin(), parent.end(), -1);
        fill(ap.begin(), ap.end(), false);
        timer = 0;
        
        // Gọi hàm đệ quy cho tất cả các đỉnh
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                bridgeUtil(i);
            }
        }
        
        // Thu thập kết quả
        vector<int> result;
        for (int i = 1; i <= V; i++) {
            if (ap[i]) {
                result.push_back(i);
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        Graph g(n);
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        
        vector<int> articulationPoints = g.findArticulationPoints();
        
        for (int i = 0; i < articulationPoints.size(); i++) {
            if (i > 0) cout << " ";
            cout << articulationPoints[i];
        }
        cout << "\n";
    }
    
    return 0;
} 