#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;
    
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        
        // Khởi tạo mỗi đỉnh là parent của chính nó
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    // Tìm parent của x với path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // Hợp nhất hai tập hợp chứa x và y
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        // Nếu đã cùng tập hợp, việc thêm cạnh sẽ tạo chu trình
        if (rootX == rootY) {
            return false;
        }
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int V, E;
        cin >> V >> E;
        
        DisjointSet ds(V);
        bool hasCycle = false;
        
        // Đọc và xử lý từng cạnh
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            
            // Nếu không thể union (đã cùng tập hợp), có chu trình
            if (!ds.unionSets(u, v)) {
                hasCycle = true;
                // Vẫn cần đọc hết các cạnh còn lại
            }
        }
        
        if (hasCycle) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 